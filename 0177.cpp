#include <iostream>
#include <cmath>
using namespace std;

const double r = 6378.1;
const double PI = acos(-1);

//球座標
struct Point {
   double x,y,z;
   Point(){}
   Point (double theta, double phi){
      x = r*sin(theta)*cos(phi);
      y = r*sin(theta)*sin(phi);
      z = r*cos(theta);      
   }
};

//3次元距離
double getDist(Point a, Point b){
   return sqrt(pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0) + pow(a.z-b.z,2.0));
}

//余弦定理
double arg2(double a, double b, double c){
   return acos((b*b+c*c-a*a)/(2*b*c));
}

int main(){
   double a,b,c,d;
   while(cin >> a >> b >> c >> d){
      if(a == -1 && b == -1 && c == -1 && d == -1)break;
      
      a = 90 - a;
      a *= PI/180.0;

      if(b > 180) b -= 360;
      if(d > 180) d -= 360;
      
      b *= PI/180.0;
      c = 90 - c;
      c *= PI/180.0;
      d *= PI/180.0;
      
      Point a1(a,b), a2(c,d);
      
      double theta = arg(getDist(a1,a2),r,r);
      cout << (int)round(theta*r) << endl;
   }
   return 0;
}
