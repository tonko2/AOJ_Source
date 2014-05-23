#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long int lli;
double const pi = acos(-1);
int main(){
  int a,b,C;
  double S,L,h,s,c;
  cin >> a >> b >> C;
  c = sqrt(a*a+b*b-2*a*b*cos(C*pi/180));
  s = (a+b+c)/2.0;
  S = sqrt(s*(s-a)*(s-b)*(s-c));
  L = a + b + c;
  h = b*sin(pi*C/180);
  cout << fixed << setprecision(8);
  cout << S << endl;
  cout << L << endl;
  cout << h << endl;
  return 0;
}
