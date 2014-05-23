#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const double EPS=1e-9;
const double INF=1e10;
const double PI = M_PI;


// 平面上の点
struct Point {
   double x,y;
   Point(double x, double y):x(x),y(y){}
   Point(){}
};

Point operator+(Point a, Point b){
   return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a, Point b){
   return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a, double b){
   return Point(a.x*b,a.y*b);
}


// 内積
double dot(Point a, Point b){
   return a.x*b.x+a.y*b.y;
}

// 外積
double cross(Point a, Point b){
   return a.x*b.y-a.y*b.x;
}

// 一致確認
bool operator==(Point a, Point b){
   return a.x == b.x && a.y == b.y;
}

// |a|^2
double norm(Point a){
   //a*b*cosθ = a*a*cos(0) = a^2
   return dot(a,a);
}

// |a|
double abs(Point a){
   return sqrt(norm(a));
}


// 角度 π*θ/180.0の値
// 第一、第二事象は正 それ以外は負になるので注意
double atan(Point a){
   return atan2(a.y,a.x);
}

Point polar(double a, double r){
   return Point(cos(r)*a, sin(r)*a);
}

struct Line :vector<Point>{
   Line(Point a = Point(0,0), Point b = Point(0,0)){
   this->push_back(a);
   this->push_back(b);
   }
};

typedef vector<Point> Polygon;

int ccw(Point a, Point b, Point c){
   b = b - a;
   c = c - a;
   if(cross(b,c) > EPS) return 1; // 反時計周り
   if(cross(b,c) < -EPS) return -1; // 時計周り
   if(dot(b,c) < 0) return 2; //c--a--bがこの順番に一直線上
   if(norm(b) < norm(c)) return -2; // a--b--cが順番に一直線上
   return 0; // a--c--bが一直線上
}


Point crosspoint_LL(Line l, Line m){
   double d = cross(m[1]-m[0],l[1]-l[0]);
   return l[0] + (l[1]-l[0]) * cross(m[1]-m[0],m[1]-l[0]) *
      (1.0 / d);
}

//凸多角形の切断
Polygon convex_cut(const Polygon& P, const Line& l) {
  Polygon Q;
  for (int i = 0; i < P.size(); ++i) {
     Point A = P[i], B = P[(i+1)%P.size()];
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspoint_LL(Line(A, B), l));
  }
  return Q;
}

Line shift(Line s, double d ){
    Point v = polar(d,atan(s[1]-s[0])+acos(-1)/2 );
    Line m = Line(s[0]+v,s[1]+v);
    return m;
}

bool check(Polygon v, double d){
   Polygon tmp = v;
   vector<Line>l;
   for(int i=0; i<v.size(); i++){
      l.push_back(Line(v[i],v[(i+1)%v.size()]));
   }

   for(int i=0; i<v.size(); i++){
      Line t = shift(l[i],d);
      tmp = convex_cut(tmp,t);
   }
   return tmp.size() == 0;
}

int main(){
   int n;
   while(cin >> n && n){
      Polygon v;
      for(int i=0; i<n; i++){
         Point p;
         cin >> p.x >> p.y;
         v.push_back(p);
      }

      double left = 0, right = 1<<29;
      for(int i=0; i<100; i++){
         double mid = (left+right)/2.0;
         if(check(v,mid)) right = mid;
         else left = mid;
      }
      printf("%.8f\n",left);
   }
   return 0;
}
