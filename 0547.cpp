#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 100000;

int main(){
   int W,H;
   while(cin >> W >> H,W|H){
      int dp[101][101][2];
      memset(dp,0,sizeof(dp));
      for(int i=1; i<=100; i++)
	 dp[i][1][0] = dp[1][i][0] = dp[i][1][1] = dp[1][i][1] = 1;

      for(int i=2; i<=H; i++){
	 for(int j=2; j<=W; j++){
	    dp[i][j][0] = (dp[i][j-1][0] + dp[i-2][j][1]) % MOD;
	    dp[i][j][1] = (dp[i][j-2][0] + dp[i-1][j][1]) % MOD;
	 }
      }

      cout << (dp[H-1][W][1] + dp[H][W-1][0]) % MOD << endl;
      
      
   }
   
   return 0;
}
