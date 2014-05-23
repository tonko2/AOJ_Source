#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
using namespace std;

int n,m,x[151][11],d[150][11],dp[150][10][77];
const int INF = 1000000000;

int main(){
	while(scanf("%d%d",&n,&m),n){
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i++){
			int k;
			scanf("%d",&k);
			for(int j = 0; j < k; j++){
				scanf("%d%d",x[i]+j,d[i]+j);
			}
			x[i][k] = 0;//番兵
		}
		//最初の石
		for(int i = 0; x[0][i]; i++){
			dp[0][i][0] = 0;
		}
		//1回ジャンプして行ける最初の石
		for(int i = 0; x[1][i]; i++){
			dp[1][i][1] = 0;
		}
		
		for(int i = 1; i < n; i++){
			for(int j = 0; j <= m; j++){
				for(int k2 = 0; x[i-1][k2]; k2++){
					for(int k = 0; x[i][k]; k++){
						if(dp[i-1][k2][j]+1) dp[i][k][j] = min(dp[i][k][j]==-1?INF:dp[i][k][j],dp[i-1][k2][j]+abs(x[i][k]-x[i-1][k2])*(d[i][k]+d[i-1][k2]));
					}
					
					for(int k = 0; x[i+1][k]; k++){
						if(dp[i-1][k2][j]+1) dp[i+1][k][j+1] = min(dp[i+1][k][j+1]==-1?INF:dp[i+1][k][j+1],dp[i-1][k2][j]+abs(x[i+1][k]-x[i-1][k2])*(d[i+1][k]+d[i-1][k2]));
					}
				}
			}
		}
		int ans = INF;
		for(int i = 0; x[n-1][i]; i++){
			for(int j = 0; j <= m; j++){
				ans = min(ans,dp[n-1][i][j]==-1?INF:dp[n-1][i][j]);
			}
		}
		
		for(int i = 0; x[n-2][i]; i++){
			for(int j = 0; j < m; j++){
				ans = min(ans,dp[n-2][i][j]==-1?INF:dp[n-2][i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
