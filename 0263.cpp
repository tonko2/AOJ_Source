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

int main(){
   int n,c;
   int dp[31][1<<16],ans,a[30],b[30];
   while(cin >> n >> c, n|c){
      ans = 0;
      memset(dp,-1,sizeof(dp));

      for(int i=0; i<n; i++){
         int in;
         a[i] = 0;
         for(int j=0; j<16; j++){
            cin >> in;
            a[i] += (in<<(15-j));
         }
      }

      for(int i=0; i<c; i++){
         int in;
         b[i] = 0;
         for(int j=0; j<16; j++){
            cin >> in;
            b[i] += (in<<(15-j));
         }
      }

      dp[0][0] = 0;

      for(int i=0; i<n; i++){
         for(int j=0; j<(1<<16); j++){
            if(dp[i][j] < 0) continue;
            for(int k=0; k<c; k++){
               int next = (a[i]|j) & (~((a[i]|j) & b[k]));
               dp[i+1][next] = max(dp[i+1][next],
                                   dp[i][j]+__builtin_popcount((a[i]|j) & b[k]));
               ans = max(ans,dp[i+1][next]);
            }
         }
      }
      cout << ans << endl;
      
   }
  return 0;
}
