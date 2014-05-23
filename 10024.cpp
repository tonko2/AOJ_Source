#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  double x1,x2,y1,y2,dis;

  cin >> x1 >> y1 >> x2 >> y2;

  dis = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
  cout << fixed << setprecision(8);
  cout << dis << endl;
  return 0;
}
