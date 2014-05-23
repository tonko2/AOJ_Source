#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;
 
//XY座標
#define X real()
#define Y imag()
 
// 許容する誤差ε
const double EPS = (1e-10);
// 円周率
const double PI = 3.14159265358979;
 
// 点の表現
typedef complex<double> P;
 
// complex<double> の順序を定義する
namespace std {
    bool operator < (const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}
 
// 2乗する
double sq(double x){
    return x * x;
}
 
// 2つのスカラーが等しいかどうか
bool equal(double a, double b){
    return ( fabs( a - b ) < EPS );
}
// 2つのベクトルが等しいかどうか
bool eq_v(P a, P b){
    return ( equal( a.X, b.X ) && equal( a.Y, b.Y ) );
}
 
// 線, 線分, 直線の表現 (これの使い道がまだ不明である !!!)
struct Line{ P pos, dir; };
// [案]
// 直線 => Line 型
// 半直線 => Ray 型
// 線分 => Segment 型
 
// 多角形の表現 (使わない可能性あり !!!)
typedef vector<P> G;
 
// 円の表現
struct Circle{
    // 円の中心
    P p;
    // 円の半径
    double r;
    // コンストラクタで初期化
    Circle(P p_, double r_){
        p = p_;
        r = r_;
    }
    // 3 点を通る円 (まだ書いてない !!! )
    Circle(P a, P b, P c){
        ;
    }
    // 円の面積
    double get_area(){
        return r * r * PI;
    }
    // 円周
    double circumference(){
        return 2.0 * r * PI;
    }
    // 点 a が円の内部にあるかどうか (未検証 ??? )
    bool is_inside(P a){
        return sq( p.X - a.X ) + sq( p.Y - a.Y ) <= r*r;
    }
    // 点 a が円周上にあるかどうか
    bool on_boundary(P a){
        return equal( sq( p.X - a.X ) + sq( p.Y - a.Y ) , r * r );
    }
    // 2 つの円の共通接線を返す (まだ書いてない !!!)
    // 2 つの円が離れている => 共通接線は 4 つ
    // 2 つの円が外接する   => 共通接線は 3 つ
    // 2 つの円が交わる     => 共通接線は 2 つ
    // 2 つの円が内接する    => 共通接線は 1 つ
    // 2 つの円のどちらかが内包する => 共通接線は 0 つ
    vector<Line> hoge_2(const Circle& cir){
        ;
    }
    // 2 つの円の交わる点を返す (まだ書いてない !!!)
    // 2 つの円が離れている・内包する => 接点は 0 つ
    // 2 つの円が外接 or 内接する   => 接点は 1 つ
    // 2 つの円が交わる            => 接点は 2 つ
    vector<P> intersection(const Circle& cir){
        ;
    }
    // 円と直線の交点を返す (まだ書いてない !!!)
    vector<P> intersection(const Line& l){
    }
    // 任意の弦の長さを返す (まだ書いてない !!!)
     
    // 円のパラメータの表示 (デバッグ用)
    void print(){
        cout << "circle : r = " << r << " p = (" << p.X << "," << p.Y << ")" << endl;
    }
};
 
// 三角形の表現
struct Triangle{
private:
    // 余弦定理から 3 つの角の角度を求める (内部の関数で使用)
    double LawOfCosines(double a, double b, double c){
        return acos( (b*b + c*c - a*a) / (2.0 * b * c) );
    }
    // ラジアンから度数へ変換して返す
    double to_degree(double radian){
        return radian * 180.0 / PI;
    }
public:
    // 3 つの頂点
    P a, b, c;
    // 3 つの辺の長さ
    double edgeA, edgeB, edgeC;
    // 3 つの角の角度 (ラジアン)
    double angleA,angleB,angleC;
     
    // コンストラクタで初期化
    Triangle(P p1, P p2, P p3){
        a = p1;
        b = p2;
        c = p3;
        edgeB = abs(c-a);
        edgeA = abs(b-c);
        edgeC = abs(a-b);
        angleA = LawOfCosines( edgeA, edgeB, edgeC );
        angleB = LawOfCosines( edgeB, edgeC, edgeA );
        angleC = LawOfCosines( edgeC, edgeA, edgeB );
    }
    // 三角形の面積を返す (ヘロンの公式)
    double get_area(){
        double s = 0.5 * (edgeA + edgeB + edgeC);
        return sqrt( s * (s - edgeA) * (s - edgeB) * (s - edgeC) );
    }
    // 三角形の重心を返す
    P gravity(){
        P g( (a.X + b.X + c.X) / 3.0 , (a.Y + b.Y + c.Y) / 3.0 );
        return g;
    }
    // 三角形の外接円を返す
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
    // 三角形の内接円を返す (未検証 ???)
    Circle inscribed_circle(){
        // 三角形の外周の長さ
        double ABC = edgeA + edgeB + edgeC;
         
        double cx = (a.X * edgeA + b.X * edgeB + c.X * edgeC) / ABC;
        double cy = (a.Y * edgeA + b.Y * edgeB + c.Y * edgeC) / ABC;
        double r  = (2.0 * get_area()) / ABC ;
        Circle cir( P(cx,cy) , r );
        return cir;
    }
    // 点 p が三角形の内部にあるかどうか (まだ書いてない !!! AOJ 0012 にあります)
   bool is_inside(Triangle t1, Triangle t2, Triangle t3, Triangle t4){
      double S = t1.get_area();
      double S1 = t2.get_area();
      double S2 = t3.get_area();
      double S3 = t4.get_area();
      if(fabs((S - (S1+S2+S3))) <= EPS) return true;
      else return false;
    }
  
}; 
 
int main(){
   double x1,x2,x3,y1,y2,y3,xp,yp;
   while(cin >> x1>>y1>>x2>>y2>>x3>>y3>>xp>>yp){
      P a(x1,y1),b(x2,y2),c(x3,y3),p(xp,yp);
      Triangle T1(a,b,c),T2(a,b,p),T3(b,c,p),T4(a,c,p);
      if(T1.is_inside(T1,T2,T3,T4)) cout << "YES" << endl;
      else cout << "NO" << endl;
   }

}
