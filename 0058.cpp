#include <iostream>
using namespace std;

int main()
{
  double x1,x2,x3,x4,y1,y2,y3,y4;
  double a,b;

  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
    a = (y2-y1)/(x2-x1);
    b = (y4-y3)/(x4-x3);

    if(a*b == -1)
      cout << "YES" << endl;
    else if(((x2-x1 == 0 && y2-y1 != 0) && (x4-x3 != 0 && y4-y3 == 0)) ||
	    (x2-x1 != 0 && y2-y1 == 0) && (x4-x3 == 0 && y4-y3 != 0))
      cout << "YES" << endl; 
    else
      cout << "NO" << endl;
  }
  return 0;
}
