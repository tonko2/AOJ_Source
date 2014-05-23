#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int H,W,N;

bool used[200][200];
int grid[200][200];

typedef pair<int,int> P;
typedef pair<int,P> PP;

int bfs(int sx, int sy, int gx, int gy){

   fill(used[0],used[200],false);
   
   priority_queue<PP,vector<PP>,greater<PP> >que;
   que.push(PP(0,P(sx,sy)));

   while(!que.empty()){
      PP p = que.top();
      que.pop();
      int x = p.second.first;
      int y = p.second.second;

      if(x == gx && y == gy) return p.first;
      if(used[y][x])continue;
      used[y][x] = true;


//      cout << "x = " << x << " y = " << y << endl;
      

      for(int i=0; i<4; i++){
         int nx = x + dx[i], ny = y + dy[i];
         int nx2 = x + 2*dx[i], ny2 = y + 2*dy[i];
         if(nx < 0 || ny < 0 || nx >= 2*W || ny >= 2*H)continue;
         if(nx2 < 0 || ny2 < 0 || nx2 >= 2*W || ny2 >= 2*H)continue;
         if(grid[ny][nx])continue;
         que.push(PP(p.first+1,P(nx2,ny2)));
      }
   }
   return -1;
}

void print(){
   for(int i=2*H-1; i>=0; i--){
      for(int j=0; j<=2*W; j++){
         cout << grid[i][j];
      }
      cout << endl;
   }
}

int main(){
   cin >> W >> H >> N;
   for(int i=0; i<N; i++){
      int x,y,x2,y2;
      cin >> x >> y >> x2 >> y2;
      if(x != 0 && x % 2 == 0) x++;
      if(x2 != 0 && x2 % 2 == 0) x2++;
      if(y != 0 && y % 2 == 0) y++;
      if(y2 != 0 && y2 % 2 == 0) y2++;
      
      for(int Y=min(y,y2); Y<=max(y,y2); Y++){
         for(int X=min(x,x2); X<=max(x,x2); X++){
            grid[Y][X] = 1;
         }
      }
   }
   
   int sx,sy,gx,gy;
   cin >> sx >> sy >> gx >> gy;
   sx *= 2;
   sy *= 2;
   gx *= 2;
   gy *= 2;

   int start = bfs(sx,sy,gx,gy);
   int ans = start;
   
   for(int x=0; x<2*W; x+=2){
      for(int y=1; y<2*H; y+=2){
         if(grid[y][x])continue;
         grid[y][x] = 1;
         int tmp = 0;
         tmp = bfs(sx,sy,gx,gy);

//         cout << "tmp = " << tmp << endl;
//         print();
//         cout << endl;
         grid[y][x] = 0;
         if(tmp == -1)continue;
         ans = max(ans,tmp);
      }
   }


   for(int y=0; y<2*H; y+=2){
      for(int x=1; x<2*W; x+=2){
         if(grid[y][x])continue;
         grid[y][x] = 1;
         int tmp = 0;
         tmp = bfs(sx,sy,gx,gy);
//         cout << "tmp = " << tmp << endl;
         grid[y][x] = 0;
         if(tmp == -1)continue;
         ans = max(ans,tmp);
      }
   }

//   cout << "ans = " << ans << endl;
//   cout << "start = " << start << endl;
   
   cout << ans - start << endl;
   
   return 0;
}
