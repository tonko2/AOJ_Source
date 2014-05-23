#include <iostream>
using namespace std;

int H,W;
int grid[11][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(){
   char c = grid[0][0];
   for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
         if(c != grid[i][j]) return false;
      }
   }
   return true;
}

void change(int x, int y, int nowColor, int nextColor){
   grid[y][x] = nowColor;
   for(int i=0; i<4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= W || ny >= H)continue;
      if(grid[ny][nx] != nextColor)continue;
      change(nx,ny,nowColor,nextColor);
   }
}

bool dfs(int cnt, int limit){
   if(cnt == limit) return check();

   int tmp[11][11];
   for(int i=0; i<H; i++)
      for(int j=0; j<W; j++) tmp[i][j] = grid[i][j];


   for(int i=0; i<3; i++){
      if(grid[0][0] == i)continue;
      change(0,0,i,grid[0][0]);
      if(dfs(cnt+1,limit)) return true;
      for(int j=0; j<H; j++){
         for(int k=0; k<W; k++){
            grid[j][k] = tmp[j][k];
         }
      }
   }
   return false;
}
int main(){
   while(cin >> W >> H, W|H){
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            char c;
            cin >> c;
            if(c == 'R') grid[i][j] = 0;
            else if(c == 'G') grid[i][j] = 1;
            else grid[i][j] = 2;
         }
      }

      int limit = 0;
      for(limit=0; ; limit++){
         if(dfs(0,limit))break;
      }
      
      cout << limit << endl;
      
   }
   return 0;
}
