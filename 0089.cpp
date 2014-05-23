#include <iostream>
#include <sstream>
using namespace std;

const int MAX = 101;
int G[MAX][MAX],dp[MAX][MAX];
int W[MAX],H = 0;
int main(){
   string s;
   while(getline(cin,s)){
      for(int i=0; i<s.size(); i++) if(s[i] == ',') s[i] = ' ';
      stringstream ss(s);
      W[H] = 0;
      while(ss >> G[H][W[H]]) W[H]++;
      H++;
   }
   dp[0][0] = G[0][0];

   for(int i=1; i<H; i++){
      for(int j=0; j<W[i]; j++){
         if(i <= H/2){
            dp[i][j] = dp[i-1][j] + G[i][j];
            if(j-1 >= 0 && j != W[i]-1)
               dp[i][j] = max(dp[i][j],dp[i-1][j-1] + G[i][j]);
         } else {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + G[i][j];
         }
      }
   }
   cout << dp[H-1][0] << endl;
   return 0;
}
