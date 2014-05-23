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

char G[71][71];
string dp[71][71];

bool is_digit(char c){
   if(c >= '0' && c <= '9') return true;
   else return false;
}

int main(){
   int H,W;
   while(cin >> W >> H &&(H,W)){
      for(int i=0; i<H; i++)
         for(int j=0; j<W; j++) cin >> G[i][j];

      fill(dp[0],dp[71],"");

      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            if(is_digit(G[i][j])){
               if(i == 0 && j == 0) dp[i][j] = G[i][j];
               else if(i == 0) dp[i][j] += dp[i][j-1] + G[i][j];
               else if(j == 0) dp[i][j] += dp[i-1][j] + G[i][j];
               else {
                  if(dp[i-1][j].size() > dp[i][j-1].size()){
                     dp[i][j] += dp[i-1][j] + G[i][j];
                  } else if(dp[i-1][j].size() < dp[i][j-1].size()){
                     dp[i][j] += dp[i][j-1] + G[i][j];
                  } else if(dp[i-1][j].size() == dp[i][j-1].size() &&
                            dp[i-1][j] > dp[i][j-1]){
                     dp[i][j] += dp[i-1][j] + G[i][j];
                  } else {
                     dp[i][j] += dp[i][j-1] + G[i][j];
                  }
               }
            } else {
               dp[i][j] = "";
            }
         }
      }

      string ans = "";
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){

            if(dp[i][j][0] == '0'){
               reverse(dp[i][j].begin(),dp[i][j].end());
               while(dp[i][j][dp[i][j].size()-1] == '0'){
                  dp[i][j].erase(dp[i][j].size()-1);
               }
               reverse(dp[i][j].begin(),dp[i][j].end());
            }
            
            if(dp[i][j].size() > ans.size()){
               ans = dp[i][j];
            } else if(dp[i][j].size() == ans.size() &&
                      dp[i][j] > ans){
               ans = dp[i][j];
            }
         }
      }

     
      cout << ans << endl;
      
   }
  return 0;
}
