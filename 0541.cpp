#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int H,W,N;

int main(){
   while(cin >> H >> W >> N,H|W|N){
      int dp[1010][1010];
      int grid[1010][1010];
      memset(dp,0,sizeof(dp));
      dp[0][0] = N - 1;

      for(int i=0; i<H; i++)
	 for(int j=0; j<W; j++) cin >> grid[i][j];

      for(int i=0; i<H; i++){
	 for(int j=0; j<W; j++){
	    
	    if(dp[i][j] % 2){
	       if(grid[i][j]){
		  dp[i][j+1] += dp[i][j]/2 + 1;
		  dp[i+1][j] += dp[i][j]/2;
	       } else {
		  dp[i][j+1] += dp[i][j]/2;
		  dp[i+1][j] += dp[i][j]/2 + 1;
	       }
	    }
	    else {
	       dp[i+1][j] += dp[i][j]/2;
	       dp[i][j+1] += dp[i][j]/2;
	    }
	 }
      }


      for(int i=0; i<H; i++){
	 for(int j=0; j<W; j++){
	    if(dp[i][j] % 2) grid[i][j] = 1 - grid[i][j];
	 }
      }

      int x = 0, y = 0;
      while(x < W && y < H){
	 if(grid[y][x]) x++;
	 else y++;
      }

      cout << y+1 << " " << x+1 << endl;
      
   }
   return 0;
}
