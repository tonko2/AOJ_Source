#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
   int N,M;
   string s;
   while(cin >> N >> M){
      vector<vector<int> >v(3);
      int cost[301];
      for(int i=0; i<N; i++){
         cin.ignore();
         getline(cin,s);
         cin >> cost[i];
         int a,b,c;
         cin >> a >> b >> c;
         v[0].push_back(a);
         v[1].push_back(b);
         v[2].push_back(c);
      }

      int dp[310][310];
      int ans = 0;


      for(int i=0; i<3; i++){
         memset(dp,0,sizeof(dp));
         for(int j=0; j<N; j++){
            for(int k=0; k<=M; k++){
               if(k < cost[j]){
                  dp[j+1][k] = dp[j][k];
               } else {
                  dp[j+1][k] = max(dp[j][k],dp[j+1][k-cost[j]] + v[i][j]);
               }
            }
         }
         ans = max(ans,dp[N][M]);
      }
      
      cout << ans << endl;
   }
   return 0;
}
