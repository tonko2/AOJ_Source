#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>
#include <cstdio>

using namespace std;

const double PI = M_PI;
const double EPS = 1e-7;

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


// 内積
double dot(Point a, Point b){
   return a.x*b.x+a.y*b.y;
}

// 外積
double cross(Point a, Point b){
   return a.x*b.y-a.y*b.x;
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


// 点の回転 angleはラジアンで与えられる 180*PI/180 = 3.1415
// x' = x*cosθ-y*sinθ
// y' = x*sinθ+y*cosθ
Point rotate(Point a, double angle){
   Point res;
   res.x = a.x * cos(angle) - a.y * sin(angle);
   res.y = a.x * sin(angle) + a.y * cos(angle);
   return res;  
}


int ccw(Point a, Point b, Point c){
   b = b - a;
   c = c - a;
   if(cross(b,c) > EPS) return 1; // 反時計周り
   if(cross(b,c) < -EPS) return -1; // 時計周り
   if(dot(b,c) < 0) return 2; //c--a--bがこの順番に一直線上
   if(norm(b) < norm(c)) return -2; // a--b--cが順番に一直線上
   return 0; // a--c--bが一直線上
}


bool checkarg(double a, double b, double c){
    double pi2 = PI * 2.0;
    while(b + EPS < a) b += pi2;
    while(b > a + pi2 + EPS) b -= pi2;
    while(c + EPS < b) c += pi2;
    while(c > a + pi2 + EPS) c -= pi2;
 
    return a < b + EPS && b < c + EPS;
}

bool reach(Point house, double d, double a, double w){
    if(norm(house) > a * a + EPS) return false;
    return checkarg(w - d * 0.5, atan(house), w + d * 0.5);
}

int main(){
  
   

   
   int H,R;
   while(cin >> H >> R,H|R){
      Point h[101];
      Point u[11],m[11],s[11];
      pair<double,double>r[101];
      vector<int>ans;
      int U,M,S;
      double du,dm,ds;
      
      for(int i=0; i<H; i++) cin >> h[i].x >> h[i].y;
      cin >> U >> M >> S >> du >> dm >> ds;
      for(int i=0; i<U; i++) cin >> u[i].x >> u[i].y;
      for(int i=0; i<M; i++) cin >> m[i].x >> m[i].y;
      for(int i=0; i<S; i++) cin >> s[i].x >> s[i].y;
      for(int i=0; i<R; i++) {cin >> r[i].first >> r[i].second; r[i].first *= PI/180.0;}
      du *= PI/180.0;
      dm *= PI/180.0;
      ds *= PI/180.0;

      Point start,start_a,start_w;
      Point high,low;
      int mincnt = 1;



         for(int i=0; i<H; i++){
            int cnt = 0;
            for(int j=0; j<R; j++){
         //自分の梅がHiに到達しているか
         bool flag = false;
         bool check = false;

            start = Point(0,0);
            start_a = Point(start.x+r[j].second,start.y);
            start_w = rotate(start_a-start,r[j].first);
            high = rotate(start_w,du/2);
            low = rotate(start_w,-du/2);
            
            /*cout << "angle = " << r[j].first << endl;
              cout << "length = " << r[j].second << endl;
              cout << "startx = " << start.x << " starty = " << start.y << endl;
              cout << "start_ax = " << start_a.x << " start_ay = " << start_a.y << endl;
              cout << "start_wx = " << start_w.x << " start_wy = " << start_w.y << endl;
              cout << "highx = " << high.x << " highy = " << high.y << endl;
              cout << "lowx = " << low.x << " lowy = " << low.y << endl;*/

            
            if(!reach(h[i],du,r[j].second,r[j].first)){
               continue;
            }

            //U
            for(int k=0; k<U; k++){
               start = u[k];
//               start_a = Point(start.x+r[j].second,start.y);
//               start_w = rotate(start_a-start,r[j].first);
//               high = rotate(start_w,du);
//               low = rotate(start_w,-du);
               
               if(!reach(h[i]-start,du,r[j].second,r[j].first)){
                  continue;
               }
               
               //   if(norm(h[i]-start) > r[j].second*r[j].second + EPS) continue;
//               if(ccw(start,h[i],high) * ccw(start,h[i],low) >= 0)continue;
               flag = true;
               break;
            }
               
            //M
            for(int k=0; k<M; k++){
               start = m[k];
//               start_a = Point(start.x+r[j].second,start.y);
//               start_w = rotate(start_a-start,r[j].first);
//               high = rotate(start_w,dm);
//               low = rotate(start_w,-dm);

               if(!reach(h[i]-start,dm,r[j].second,r[j].first)){
                  continue;
               }
               
//               if(norm(h[i]-start) > r[j].second*r[j].second + EPS) continue;
//               if(ccw(start,h[i],high) * ccw(start,h[i],low) >= 0)continue;
               flag = true;
               break;
            }
               
            //S
            for(int k=0; k<S; k++){
               start = s[k];
//               start_a = Point(start.x+r[j].second,start.y);
//               start_w = rotate(start_a-start,r[j].first);
//               high = rotate(start_w,ds);
//               low = rotate(start_w,-ds);

               
               if(!reach(h[i]-start,ds,r[j].second,r[j].first)){
                  continue;
               }
//               if(norm(h[i]-start) > r[j].second*r[j].second + EPS) continue;
//               if(ccw(start,h[i],high) * ccw(start,h[i],low) >= 0)continue;
               flag = true;
               break;
            }
               
            if(flag){
               check = true;
            }
            if(!check) cnt++;
           
         }
         if(cnt > mincnt){
            mincnt = cnt;
            ans.clear();
         }
         if(cnt == mincnt){
            ans.push_back(i+1);
         }
      }

      if(ans.size() == 0) {cout << "NA" << endl; continue;}
      for(int i=0; i<ans.size(); i++){
         if(i == 0) cout << ans[i];
         else cout << " " << ans[i];
      }
      cout << endl;

      
   }
   return 0;
}
