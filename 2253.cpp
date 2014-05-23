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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,1,0,-1,-1};
int dy[] = {1,1,0,-1,-1,0};

const int MAX = 210;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int t,n;
bool used[MAX][MAX];
int d[MAX][MAX];

void bfs(int sx, int sy){
   d[sy][sx] = 0;

   queue<P>que;
   que.push(mp(sy,sx));
   while(!que.empty()){
      P p = que.front();
      que.pop();
      int x = p.second, y = p.first;

      int ncost = d[y][x] + 1;
      if(ncost > t)break;

      for(int i=0; i<6; i++){
         int nx = x + dx[i], ny = y + dy[i];
         if(used[ny][nx])continue;
         used[ny][nx] = true;
         que.push(mp(ny,nx));
         d[ny][nx] = ncost;
      }
   }
}

int main(){
   while(cin >> t >> n,t|n){
      fill(used[0],used[MAX],false);
      fill(d[0],d[MAX],INF);
      int sx = MAX/2, sy = MAX/2;
      for(int i=0; i<n; i++){
         int x,y;
         cin >> x >> y;
         used[y+sy][x+sx] = true;         
      }
      int x,y;
      cin >> x >> y;
      bfs(x+sx,y+sy);
      int ans = 0;
      for(int i=0; i<MAX; i++){
         for(int j=0; j<MAX; j++){
            if(d[i][j] != INF)ans++;
         }
      }
      cout << ans << endl;
   }
  return 0;
}
