#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
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

// 必要時定義
Point operator*(Point a, Point b){
   return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

// 必要時定義 (基本的に * 1.0 / (ほげほげ) で済ます
Point operator/(Point a, double b){
   return Point(a.x / b, a.y / b);
}

struct Circle: Point {
   double r;
   Circle(Point p = Point(0,0), double r = 0):Point(p),r(r){}
};

double dot(Point a, Point b){
   return a.x*b.x + a.y*b.y;
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

bool is_intersect_CP(Circle c, Point p){
   return abs(c-p) < c.r;
}


struct Line :vector<Point>{
   Line(Point a = Point(0,0), Point b = Point(0,0)){
   this->push_back(a);
   this->push_back(b);
   }
};


Point projection(Line l, Point p){
   double t = dot(p-l[0],l[1]-l[0]) / norm(l[0]-l[1]);
   return l[0] + (l[1] - l[0]) * t;
}

//円と線分の交点の数
int intersectCS(Circle c, Line l){ 
    if(norm(projection(l, c) - c) - c.r*c.r > EPS) return 0;
    double d1 = abs(c - l[0]);
    double d2 = abs(c - l[1]);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS
       || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    Point h = projection(l, c);
    if(dot(l[0] - h, l[1] - h) < 0) return 2;
    return 0;
}

int main(){
   int n,m;
   while(cin >> n && n){
      Circle c[101];
      for(int i=0; i<n; i++){
         cin >> c[i].x >> c[i].y >>c[i].r;
      }
      cin >> m;
      while(m--){
         double tx,ty,sx,sy;
         cin >> tx >> ty >> sx >> sy;
         Line l = Line(Point(tx,ty),Point(sx,sy));
         for(int i=0; i<n; i++){
            if(intersectCS(c[i],l)){
               cout << "Safe" << endl;
               break;
            } else if(i == n-1){
               cout << "Danger" << endl;
            }
         }
      }
   }
}
