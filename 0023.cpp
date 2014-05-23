#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

typedef complex<double> Point;
#define x real()
#define y imag()
#define EPS 1e-10
#define equals(a,b) (fabs((a)-(b)) < EPS)

static const double PI = acos(-1);
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Circle{
   double r;
   Point p;
   Circle(Point p_, double r_){
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
   Point a,b,c;
   double edgeA,edgeB,edgeC;
   double angleA,angleB,angleC;
   Triangle(Point p1, Point p2, Point p3){
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

   //���ܱ�
   Circle circumscribed_circle(){
      double r = ( edgeA / sin(angleA) / 2.0 );
      double A = sin( 2.0 * angleA );
      double B = sin( 2.0 * angleB );
      double C = sin( 2.0 * angleC );
      double cx = ( (a.x * A + b.x * B + c.x * C) / (A+B+C) );
      double cy = ( (a.y * A + b.y * B + c.y * C) / (A+B+C) );
      Circle cir( Point(cx,cy) , r );
      return cir;
   }
};

struct Segment{
   Point p1,p2;
};





//����
double dot(Point a, Point b){
   return a.x*b.x + a.y*b.y;
}

//����
double cross(Point a, Point b){
   return a.x*b.y - a.y*b.x;
}

//�٥��ȥ�a,b��ľ��Ƚ��
bool isOrthogonal(Point a, Point b){
   return equals(dot(a,b),0.0);
}

//a1��a2����ʬ��b1��b2����ʬ�Ȥ�ľ��Ƚ��
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
   return isOrthogonal(a1-a2,b1-b2);
}

//��ʬs1,s2��ľ��Ƚ��
bool isOrthogonal(Segment s1, Segment s2){
   return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

//�٥��ȥ�a,b��ʿ��Ƚ��
bool isParallel(Point a, Point b){
   return equals(cross(a,b),0.0);
}

//a1��a2����ʬ��b1��b2����ʬ�Ȥ�ʿ��Ƚ��
bool isParallel(Point a1, Point a2, Point b1, Point b2){
   return isParallel(a1-a2,b1-b2);
}

//��ʬs1,s2��ʿ��Ƚ��
bool isParallel(Segment s1, Segment s2){
   return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1),0.0);
}

//��ʬs�ȥ٥��ȥ�p�θ����κ�ɸ
Point project(Segment s, Point p){
   Point base = s.p2 - s.p1;
   double t = dot(p - s.p1,base) / norm(base);
   return s.p1 + base * t;
}

//��ʬs���оμ��Ȥ�����p�����оΤ���x
Point reflect(Segment s, Point p){
   return p + (project(s,p) - p) * 2.0;
}

int ccw(Point p0, Point p1, Point p2){
   Point a = p1 - p0;
   Point b = p2 - p0;
   if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
   if(cross(a,b) < EPS) return CLOCKWISE;
   if(dot(a,b) < -EPS) return ONLINE_BACK;
   if(norm(a) < norm(b)) return ONLINE_FRONT;
   return ON_SEGMENT;
}

double dis(Point a, Point b){
   return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}

int main(){
   int n;
   cin >> n;
   for(int i=0; i<n; i++){
      Point p1,p2;
      double r1,r2;
      cin >> p1.x >> p1.y >> r1 >> p2.x >> p2.y >> r2;
      Circle c1(p1,r1);
      Circle c2(p2,r2);
      double s = dis(c1.p,c2.p);
      if(r1 - s - r2 > EPS) cout << 2 << endl;
      else if(r2 - s - r1 > EPS) cout << -2 << endl;
      else if(r1 + r2 - s >= 0) cout << 1 << endl;
      else cout << 0 << endl;
   }
   return 0;
}
