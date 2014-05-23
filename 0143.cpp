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

typedef vector<Point> Polygon;

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

// 角度 π*θ/180.0の値
double atan(Point a){
   return atan2(a.y,a.x);
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

struct Line :vector<Point>{
   Line(Point a = Point(0,0), Point b = Point(0,0)){
   this->push_back(a);
   this->push_back(b);
   }
};


int ccw(Point a, Point b, Point c){
   b = b - a;
   c = c - a;
   if(cross(b,c) > EPS) return 1; // 反時計周り
   if(cross(b,c) < -EPS) return -1; // 時計周り
   if(dot(b,c) < 0) return 2; //c--a--bがこの順番に一直線上
   if(norm(b) < norm(c)) return -2; // a--b--cが順番に一直線上
   return 0; // a--c--bが一直線上
}

// 写像
Point projection(Line l, Point p){
   double t = dot(p-l[0],l[1]-l[0]) / norm(l[0]-l[1]);
   return l[0] + (l[1] - l[0]) * t;
}

// 反射
Point reflection(Line l, Point p){
   return p + (projection(l,p) - p) * 2;
}

// 直線交差判定
// 同一直線の場合は交差していると判定する
bool is_intersect_LL(Line l, Line m){
   return abs(cross(l[1]-l[0],m[1]-m[0])) > EPS || // 傾きが異なる
      abs(cross(l[1]-l[0],m[1]-m[0])) < EPS;
}

// 直線と線分の交差判定
// 同一直線上にある場合も交差と判定
bool is_intersect_LS(Line l, Line s){
   return cross(l[1]-l[0],s[0]-l[0]) *
      cross(l[1]-l[0],s[1]-l[0]) < EPS;
}

// 直線が線分を含むかの判定
bool is_intersect_LP(Line l, Point p){
   return abs(ccw(l[0],l[1],p)) != 1;
}

// 線分交差判定
bool is_intersect_SS(Line s, Line t){
   return ccw(s[0],s[1],t[0]) * ccw(s[0],s[1],t[1]) < 0 &&
      ccw(t[0],t[1],s[0]) * ccw(t[0],t[1],s[1]) < 0;
}

//多角形の中に点があるか 線分を含まない 
bool isInside(Polygon gon, Point p ){
   int array[1000];
   fill(array,array+1000,0);
   for ( int i = 0; i < gon.size(); i++ ){
      array[i] = ccw(gon[i], gon[(i+1)%gon.size()], p);
   }
   for(int i=0; i<gon.size()-1; i++){
      if(array[i] != array[i+1]) return false;
   }
   return (true);
}

// 線分と三角形の交差判定
bool is_intersectLT(Line l, Point a, Point b, Point c){
   if(ccw(l[0],l[1],a) * ccw(l[0],l[1],b) < 0 &&
      ccw(l[0],l[1],b) * ccw(l[0],l[1],c) < 0 &&
      ccw(l[0],l[1],c) * ccw(l[0],l[1],a) < 0) return true;
   return false;
}

int main(){
   int n;
   cin >> n;
   while(n--){
      double xp1,yp1,xp2,yp2,xp3,yp3,xk,yk,xs,ys;
      cin >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3
          >> xk >> yk >> xs >> ys;
      Point ta(Point(xp1,yp1));
      Point tb(Point(xp2,yp2));
      Point tc(Point(xp3,yp3));
      Point sp(Point(xk,yk));
      Point gp(Point(xs,ys));
      Line l1(ta,tb);
      Line l2(tb,tc);
      Line l3(tc,ta);
      Line S(sp,gp);
      Polygon p;
      p.push_back(ta);
      p.push_back(tb);
      p.push_back(tc);
      if(isInside(p,sp) != isInside(p,gp)){
         cout << "OK" << endl;
         continue;
      }
      
      if(ccw(sp,gp,ta) * ccw(sp,gp,tb) < 0 &&
         ccw(sp,gp,tb) * ccw(sp,gp,tc) < 0 &&
         ccw(sp,gp,tc) * ccw(sp,gp,ta) < 0){
         cout << "OK" << endl;
         continue;
      }

         cout << "NG" << endl;
   }
   return 0;
}
