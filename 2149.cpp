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
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int n,a,b,c,x;
   int y[101];

   while(cin >> n >> a >> b >> c >> x,n|a|b|c|x){
      for(int i=0; i<n; i++) cin >> y[i];

      int cnt = 0;
      int now = 0;
      while(1){
         if(y[now] == x){
            now++;
         }
         if(now == n) break;
         x = (a * x + b) % c;
         cnt++;
         if(cnt > 10000)break;
      }
      if(cnt > 10000) cout << -1 << endl;
      else cout << cnt << endl;
   }
  return 0;
}
