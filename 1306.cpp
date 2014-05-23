#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0; i<(int)n; i++)
const int INF = 1<<29;
using namespace std;

int main(){
   int n;
   while(cin >> n && n){
      int p[n+1],t[n+1];
      rep(i,n) cin >> p[i] >> t[i];
      p[n] = 0, t[n] = INF;

      int dp[n+2][4];
      fill(dp[0],dp[n+2],INF);
      dp[0][0] = 0;

      int cur = 0, tt = 0, fail = 0;
      rep(i,n+1){
         int np = p[i];
         int res = t[i]-tt;
         int dis = abs(np-cur);
         rep(j,4){
            if(j == 3){
               if(res-cur*(j+1)-np >= 0)
                  dp[i+1][1] = min(dp[i+1][1],dp[i][j]+cur+np);
            } else {
               if(res-cur*(j+1)-np >= 0) dp[i+1][1] = min(dp[i+1][1],dp[i][j]+cur+np);
               if(res-dis*(j+1)>=0) dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+dis);
            }
         }
         
         bool flag = false;
         rep(j,4)
            if(dp[i+1][j] != INF) flag = true;
         if(!flag) {fail = i + 1; break; }
         cur = np;
         tt = t[i];
      }
      if(fail) cout << "NG " << fail << endl;
      else {
         int ans = INF;
         rep(i,4) ans = min(dp[n+1][i],ans);
         cout << "OK " << ans << endl;
      }
   }
   return 0;
}
