#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  double x1,y1,x2,y2,Ax,Ay,X,Y;
  double x,y,m,n;
  char comma;
  while(cin >> x1 >> comma >> y1 >> comma >> x2 >> comma >> y2 >>
	comma >> Ax >> comma >> Ay){
    cout << fixed << setprecision(6);
    if(fabs(x2-x1) == 0) cout << x2-(Ax-x2) << ' ' << Ay << endl;
    else if(fabs(y2-y1) == 0) cout << Ax << ' ' << y2-(Ay-y2) << endl;
    else{
    m = (y2-y1) / (x2-x1);
    n = m * -x1 + y1;

    X = (m*Ay+Ax+m*Ay-2*m*n-m*m*Ax)/(m*m+1);
    Y = (-X+Ax+m*Ay) / m;
   
    cout << X << ' ' << Y << endl;
    }
  }
  return 0;
}
