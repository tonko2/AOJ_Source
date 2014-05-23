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

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int cost[10][10];
int dp[1<<10][10];
int w,h;
int bfs(vector<string>v, P p1, P p2){
   queue<P>que;
   int used[21][21];
   memset(used,-1,sizeof(used));
   used[p1.first][p1.second] = 0;
   que.push(p1);
   while(!que.empty()){
      P tmp = que.front();
      que.pop();

      if(tmp == p2) return used[tmp.first][tmp.second];         

      int x = tmp.second, y = tmp.first;
      for(int i=0; i<4; i++){
         int nx = x + dx[i], ny = y + dy[i];
         if(used[ny][nx] != -1)continue;
         if(nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
         if(v[ny][nx] == 'x')continue;
         used[ny][nx] = used[y][x]+1;
         que.push(P(ny,nx));
      }
   }
   return INF;
}

int main(){

   while(cin >> w >> h && w && h){
      vector<string>v(h);
      for(int i=0; i<h; i++) cin >> v[i];

      P start;
      vector<P>pos;
      for(int i=0; i<h; i++){
         for(int j=0; j<w; j++){
            if(v[i][j] == 'o') start = P(i,j);
            else if(v[i][j] == '*') pos.push_back(P(i,j));
         }
      }

      int N = pos.size();
      fill(cost[0],cost[N],INF);

      for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
            if(i == j) cost[i][i] = 0;
            else cost[i][j] = bfs(v,pos[i],pos[j]);
         }
      }
      
      fill(dp[0],dp[1<<N],INF);

      for(int i=0; i<N; i++) dp[1<<i][i] = bfs(v,start,pos[i]);

      for(int i=0; i<1<<N; i++){
         for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
               if(cost[j][k] != INF)
                  dp[i|1<<k][k] = min(dp[i|1<<k][k],dp[i][j]+cost[j][k]);
            }
         }
      }
            

      int ans = INF;
      for(int i=0; i<N; i++){
         ans = min(ans,dp[(1<<N)-1][i]);
      }

      if(ans == INF) cout << -1 << endl;
      else cout << ans << endl;
      
   }
  return 0;
}
