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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 1001;
const int INF = INT_MAX;
const int MOD = 100000007;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int r,c,sx,sy,gx,gy,ans,cnt;
int d[MAX][MAX];
int field[MAX][MAX];
int used[MAX][MAX];

void bfs(){
   queue<P>que;
   que.push(mp(sy,sx));
   fill(d[0],d[MAX],INF);
   fill(used[0],used[MAX],0);
   d[sy][sx] = 0;
   used[sy][sx] = 1;
   while(!que.empty()){
      P p = que.front();
      que.pop();
      int x = p.second, y = p.first;
      if(x == gx && y == gy) break;

      int cnt = d[y][x]+1;
      
      for(int i=0; i<4; i++){
         int nx = (c + x + dx[i]) % c;
         int ny = (r + y + dy[i]) % r;

         if(d[ny][nx] < cnt)continue;
         if(d[ny][nx] > cnt) que.push(mp(ny,nx));
         
         used[ny][nx] += used[y][x];
         used[ny][nx] %= MOD;
         d[ny][nx] = cnt;

      }
   }
}
int main(){
   while(cin >> r >> c >> sy >> sx >> gy >> gx){
      bfs();
      cout << used[gy][gx] << endl;
   }
  return 0;
}
