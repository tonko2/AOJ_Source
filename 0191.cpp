#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 101;
int main(){
   int n,m;
   double dp[MAX][MAX];
   double table[MAX][MAX];
   while(scanf("%d%d",&n,&m) != EOF){
      if(n == 0 && m == 0)break;
      double ans = 0;
      fill(dp[0],dp[MAX],0);
      for(int i=0; i<n; i++) dp[0][i] = 1;
      
      for(int i=0; i<n; i++)
         for(int j=0; j<n; j++) cin >> table[i][j];
      
      for(int k=0; k<m; k++){
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               dp[k+1][j] = max(dp[k+1][j],dp[k][i] * table[i][j]);
            }
         }
      }
      
      for(int i=0; i<n; i++) ans = max(ans,dp[m-1][i]);
      
      printf("%.2f\n",ans);
   }
   return 0;
}
