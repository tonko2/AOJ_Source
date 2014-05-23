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
#include <stack>
#include <sstream>
#include <climits>
using namespace std;

typedef long long int lli;
int cnt,res,ans,n;
void calc(int x){
  if(res == n && cnt >= 2){
    ans++;
    cnt = 0;
    res = 0;
    return;
  }
  else if(res > n) return;

  res += x;
  cnt++; 
  calc(x+1);
}
int main(){
  while(cin >> n && n){
    vector<int>v;
    ans = 0;
    for(int i=1; i<=n; i++){
      res = cnt = 0;
      calc(i);
    }
    cout << ans << endl;
  }
  return 0;
}
