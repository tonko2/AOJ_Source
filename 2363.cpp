#include <iostream>
using namespace std;

const double EPS = 1e-7;
int main(){
  int t,n,m,v,p;
  double r,q,ave,ans=0,ans2=0,cnt;
  ave = cnt = 0;
  cin >> t;
  for(int test=0; test<t; test++){
    cin >> n >> m;
    for(int i=0; i<m; i++){
      cin >> v >> r;
      ave += v*r;
      cnt += r;
    }
    ave /= cnt;
    ans = max(ans,ave);
    ave = cnt  = 0;
  }
  ave = cnt = 0;
  cin >> p >> q;
  for(int i=0; i<q; i++){
    cin >> v >> r;
    ave += v*r;
    cnt += r;
  }
  ave /= cnt;


  if(ans > ave+EPS) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
  
