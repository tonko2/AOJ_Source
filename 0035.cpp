#include <iostream>
#include <complex>
using namespace std;

typedef complex<double>P;

// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
    ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

int main(){
  double x1,x2,x3,x4,y1,y2,y3,y4;
  char c;

  while(cin >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3
	>> c >> x4 >> c >> y4){
    P a(x1,y1);
    P b(x2,y2);
    P c(x3,y3);
    P d(x4,y4);

    if(is_intersected_ls(a,b,c,d) > 0 || is_intersected_ls(a,c,b,d) > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
