#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1<<29;
int main(int argc, char *argv[])
{
   int n;
   while(cin >> n && n){
      int a[16][17];
      for(int i=0; i<n; i++)
         for(int j=0; j<n+1; j++) cin >> a[i][j];

      int dp[1<<16];
      fill(dp,dp+(1<<n),INF);
      dp[0] = 0;
      for(int S=0; S<(1<<n); S++){
         for(int u=0; u<n; u++){
            if(S & (1<<u))continue;
            int minValue = a[u][0];
            for(int v=0; v<n; v++){
               if((S & (1<<v)) == 0)continue;
                  minValue = min(minValue,a[u][v+1]);
            }
            dp[S|1<<u] = min(dp[S|1<<u],dp[S]+minValue);
            
         }
      }
      cout << dp[(1<<n)-1] << endl;
   }
   return 0;
}
