#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> P;
const int MAX = 62;
const int INF = 1<<30;
int w,h,ans;
int d[MAX][MAX];
bool field[MAX][MAX];
int dx[] = {0,1,0,-1};
int dy[] = {2,0,-2,0};
int sx,sy,gx,gy;

int bfs(){
   fill(d[0],d[MAX],INF);
   queue<P>que;
   que.push(make_pair(sy,sx));
   d[sy][sx] = 0;
   int res = INF;
   while(!que.empty()){
      P p = que.front();

      que.pop();
      int x = p.second, y = p.first;
      if(x == gx && y == gy){
         res = d[gy][gx];
         break;
      }
      for(int i=0; i<4; i++){
         int nx = x + dx[i], ny = y + dy[i];
         if(nx < 0 || ny < 0 || 2*h-1 <= ny
            || w <= nx || d[ny][nx] != INF)continue;
         if(i == 0)
            if(field[y+1][x])continue;
            else if(i == 2)
               if(field[y-1][x])continue;            
               else {
                  if(i == 1 && field[y][x]) continue;
                  else if(i == 3 && field[ny][nx])continue;
               }
         que.push(P(ny,nx));
         d[ny][nx] = d[y][x] + 1;
      }
   }
   return res;
}
int main(int argc, char *argv[])
{
   while(cin >> w >> h,w|h){
      fill(field[0],field[MAX],false);
      for(int i=0; i<2*h-1; i++){
         int W;
         if(i%2 == 0) W = w-1;
         if(i%2 != 0) W = w;
         for(int j=0; j<W; j++){
            cin >> field[i][j];
         }
      }
      
      sx = 0, sy = 0, gx = w-1, gy = 2* h - 2;
      ans = bfs();
      if(ans == INF) cout << 0 << endl;
      else cout << ans+1 << endl;
   }
   return 0;
}
