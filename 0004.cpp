#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double a,b,c,d,e,f,t,x,y;

  while(cin >> a >> b >> c >> d >> e >> f){
    t = a*e - b*d;

    x =  (e*c-b*f)/t;
    y =  (a*f-d*c)/t;
    
    if(x == -0)
      x = fabs(x);
    if(y == -0)
      y = fabs(y);

    cout << fixed << setprecision(3);
    cout << x << ' ' << y << endl;
  }
  return 0;
}
