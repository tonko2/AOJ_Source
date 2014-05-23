#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const double pi = acos(-1);
int main(){
  vector<pair<double,double> >ans;
  double theta=0,a=1,b=1,c,x,y;
  int n;
  ans.push_back(make_pair(1,0));
  for(int i=1; i<=1000; i++){
    c = sqrt(a*a+b*b);
    theta += atan(b/a);
    x = c*cos(theta);
    y = c*sin(theta);
    ans.push_back(make_pair(x,y));
    a = c;
  }

  while(cin >> n, n!=-1){
    cout << fixed << setprecision(2);
    cout << ans[n-1].first << endl;
    cout << ans[n-1].second << endl;
  }
  return 0;
}
