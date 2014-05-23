#include <iostream>
using namespace std;

typedef long long ll;
int main(){
   int n;
   while(cin >> n, n){
      ll dp[31];
      fill(dp,dp+31,0);
      dp[0] = 1;
      for(int i=1; i<=n; i++){
         if(i-1 >= 0) dp[i] += dp[i-1];
         if(i-2 >= 0) dp[i] += dp[i-2];
         if(i-3 >= 0) dp[i] += dp[i-3];
      }

      cout << dp[n]/3650 + ((dp[n]%3650)?1:0) << endl;
   }
   return 0;
}
