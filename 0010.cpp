#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
#define X real()
#define Y imag()

typedef complex<double> P;

struct Circle{
   P p;
   double r;
   Circle(P p_, double r_){
      p = p_;
      r = r_;
   }
};
struct Triangle{
private:
   double LawOfConsines(double a, double b, double c){
      return acos((b*b + c*c - a*a) / (2.0 * b * c));
   }
public:
   P a,b,c;
   double edgeA,edgeB,edgeC;
   double angleA,angleB,angleC;
   Triangle(P p1, P p2, P p3){
      a = p1;
      b = p2;
      c = p3;
      edgeB = abs(c-a);
      edgeA = abs(b-c);
      edgeC = abs(a-b);
      angleA = LawOfConsines(edgeA,edgeB,edgeC);
      angleB = LawOfConsines(edgeB,edgeC,edgeA);
      angleC = LawOfConsines(edgeC,edgeA,edgeB);
   }

   Circle circumscribed_circle(){
      double r = ( edgeA / sin(angleA) / 2.0 );
      double A = sin( 2.0 * angleA );
      double B = sin( 2.0 * angleB );
      double C = sin( 2.0 * angleC );
      double cx = ( (a.X * A + b.X * B + c.X * C) / (A+B+C) );
      double cy = ( (a.Y * A + b.Y * B + c.Y * C) / (A+B+C) );
      Circle cir( P(cx,cy) , r );
      return cir;
   }
};
int main(){
   int n;
   cin >> n;
   while(n--){
      double x1,x2,x3,y1,y2,y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      P a(x1,y1),b(x2,y2),c(x3,y3);
      Triangle T(a,b,c);
      Circle cir = T.circumscribed_circle();
      printf("%.3f %.3f %.3f\n",cir.p.X,cir.p.Y,cir.r);
   }
   return 0;
}
