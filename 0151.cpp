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


const int MAX = 260;
int dp[MAX][MAX][8];
char G[MAX][MAX];
int dx[] = {0,1,1,1,-1,-1,-1,0};
int dy[] = {1,0,-1,1,-1,1,0,-1};
int main(){
   int n;
   while(cin >> n && n){
      cin.ignore();
      for(int i=0; i<=MAX; i++)
         for(int j=0; j<=MAX; j++) G[i][j] = '0';

      for(int i=1; i<=n; i++)
         for(int j=1; j<=n; j++) cin >> G[i][j];
      
      memset(dp,0,sizeof(dp));

      for(int i=0; i<=n+1; i++){
         for(int j=0; j<=n+1; j++){
            for(int k=0; k<8; k++){
               int nx = j + dx[k], ny = i + dy[k];
               if(ny < 0 || nx < 0 || ny > n+1 || nx > n+1) continue;
               if(G[ny][nx] == '1'){
                  dp[ny][nx][k] = max(dp[ny][nx][k],dp[i][j][k] + 1);
               }
            }
         }
      }

      int ans = 0;
      for(int i=0; i<=n+1; i++){
         for(int j=0; j<=n+1; j++){
            for(int k=0; k<8; k++){
               ans = max(ans,dp[i][j][k]);
            }
         }
      }
      cout << ans << endl;
   }
  return 0;
}
