#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)
typedef pair<int,int> P;

class State{
public:
   int cnt,stonex,stoney,parsonx,parsony;
   int grid[10][10];

   State(int c, int sx, int sy, int px, int py, int g[10][10]){
      cnt = c, stonex = sx, stoney = sy, parsonx = px, parsony = py;
      rep(i,10)
         rep(j,10) grid[i][j] = g[i][j];
   }
   
   bool operator < (const State &s) const {
      if(cnt != s.cnt) return cnt > s.cnt;
   }
};

int w,h;
int grid[10][10];
int gx,gy;
int stonex,stoney;
int parsonx,parsony;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
set<pair<P,P> >s; //parson, stone

bool isMove(int x, int y, int Nx, int Ny, int g[10][10]){
   bool used[10][10];
   fill(used[0],used[10],0);

//   cout << "XX = " << x << " YY = " << y << endl;
   queue<P>que;
   que.push(P(x,y));
   while(!que.empty()){
      int X = que.front().first, Y = que.front().second;
//      cout << "X = " << X << " Y = " << Y << endl;
      que.pop();
      used[Y][X] = true;
      if(Y == Ny && X == Nx) return true;
      rep(i,4){
         int nx = X + dx[i], ny = Y + dy[i];
         if(nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
         if(g[ny][nx] == 1 || g[ny][nx] == 2)continue;
         if(used[ny][nx])continue;
         que.push(P(nx,ny));
      }
   }
   return false;
}

void print(int grid[10][10]){
   rep(i,h){
      rep(j,w){
         cout << grid[i][j];
      }
      cout << endl;
   }
   cout << endl;
   
}

int bfs(){
   priority_queue<State>que;
   que.push(State(0,stonex,stoney,parsonx,parsony,grid));

   while(!que.empty()){
      State tmp = que.top();
      que.pop();
      int Px = tmp.parsonx;
      int Py = tmp.parsony;
      int Sx = tmp.stonex;
      int Sy = tmp.stoney;
      int cnt = tmp.cnt;
      pair<P,P> p = pair<P,P>(P(Px,Py),P(Sx,Sy));
      if(Sx == gx && Sy == gy) return cnt;
      if(s.count(p))continue;
      s.insert(p);

//      cout << "Px = " << Px << " Py = " << Py << endl;
//      cout << "Sx = " << Sx << " Sy = " << Sy << endl;


      rep(i,4){
         int nx = Sx + dx[i], ny = Sy + dy[i];
         State t = tmp;
         if(nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
         if(tmp.grid[ny][nx] == 1)continue;
         int Nx = Sx;
         int Ny = Sy;
         if(Sx-dx[i] < 0 || Sy-dy[i] < 0 || Sx-dx[i] >= w || Sy-dy[i] >= h)continue;
         if(!isMove(Px,Py,Sx-dx[i],Sy-dy[i],tmp.grid))continue;
//         cout << "fromx = " << Px << " tox = " << Sx-dx[i] << endl;
//         cout << "fromy = " << Py << " toy = " << Sy-dy[i] << endl;
         t.grid[Py][Px] = 0;
         t.grid[ny][nx] = 2;
         t.grid[Sy][Sx] = 4;


//         print(tmp.grid);
         
         que.push(State(cnt+1,nx,ny,Sx,Sy,t.grid));
      }
      
   }
   return -1;
}
int main(){
   while(cin >> w >> h,w|h){
      s.clear();
      rep(i,h){
         rep(j,w){
            cin >> grid[i][j];
            
            if(grid[i][j] == 4){
               parsonx = j;
               parsony = i;
            }

            if(grid[i][j] == 3){
               gx = j;
               gy = i;
            }

            if(grid[i][j] == 2){
               stonex = j;
               stoney = i;
            }
            
         }
      }
      cout << bfs() << endl;
   }
   return 0;
}
