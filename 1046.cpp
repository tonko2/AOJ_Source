#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char grid[21][21];

int main(){
   int H,W;

   while(cin >> H >> W,H|W){
      vector<int>v[21][21];
      string ope;
      int Ax,Ay,Bx,By;
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){Ax = j, Ay = i;}
            if(grid[i][j] == 'B'){Bx = j, By = i;}
         }
      }

      cin >> ope;

      int cnt = 1;
      int x = Bx, y = By;
      while(cnt <= 10000){
         for(int i=0; i<ope.size(); i++){
            int nx = x,ny = y;
            if(ope[i] == '5');
            if(ope[i] == '8') ny += -1;
            if(ope[i] == '6') nx += 1;
            if(ope[i] == '4') nx += -1;
            if(ope[i] == '2') ny += 1;
            
            if(nx < 0 || ny < 0 || nx >= W || ny >= H){
               nx = x, ny = y;
            }
            
            v[ny][nx].push_back(cnt);
            x = nx, y = ny;
            cnt++;
         }
      }

      int ans = 1<<29;
      int ansx = 0, ansy = 0;
      int used[21][21];
      fill(used[0],used[21],-1);
      queue<P>que;
      que.push(P(Ax,Ay));
      used[Ay][Ax] = 0;
      while(!que.empty()){
         P p = que.front();
         que.pop();
         int x = p.first, y = p.second;
         for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H)continue;
            if(used[ny][nx] != -1)continue;
            if(grid[ny][nx] == '#')continue;
            used[ny][nx] = used[y][x] + 1;
            que.push(P(nx,ny));
         }
      }

      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            if(used[i][j] == -1)continue;
            if(grid[i][j] == '#')continue;
            for(int k=0; k<v[i][j].size(); k++){
               if(used[i][j] <= v[i][j][k]){
                  if(ans > v[i][j][k]){
                     ans = v[i][j][k];
                     ansx = j;
                     ansy = i;
                  }
               }
            }
         }
      }
      
      if(ans == 1<<29) cout << "impossible" << endl;
      else cout << ans << " " << ansy << " " << ansx << endl;
   }
   return 0;
}
