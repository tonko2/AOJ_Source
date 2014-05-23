#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)

const int MAX = 91;
bool grid[MAX][MAX];
int m,n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class State{
public:
   int cnt,x,y;
   bool g[MAX][MAX];

   State(int c, int xx, int yy, bool gg[MAX][MAX]){
      cnt = c;
      x = xx;
      y = yy;
      rep(i,n)
         rep(j,n) g[i][j] = gg[i][j];
   }
   
   bool operator < (const State &s) const {
      if(cnt != s.cnt) return cnt < s.cnt;
      if(x != s.x) return x < s.x;
      if(y != s.y) return y < s.y;
   }
};


set<State>s;

int bfs(){
   queue<State>que;
   rep(i,n){
      rep(j,n){
         if(grid[i][j]){
            State tmp(0,j,i,grid);
            que.push(tmp);
         }
      }
   }

   int ans = 0;
   while(!que.empty()){
      State tmp = que.front();
      que.pop();
      int cnt = tmp.cnt;
      int x = tmp.x;
      int y = tmp.y;
      ans = max(ans,cnt);

      if(s.count(tmp))continue;
      s.insert(tmp);

      rep(i,4){
         int nx = x + dx[i], ny = y + dy[i];
         State t = tmp;
         if(nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
         if(tmp.g[ny][nx] == 0)continue;
         t.g[ny][nx] = 0;
         t.x = nx, t.y = ny;
         t.cnt++;
         que.push(t);
      }
   }
   return ans;
}



int main(){

   while(cin >> m >> n,m|n){
      s.clear();
      
      rep(i,m)
         rep(j,n) cin >> grid[i][j];

      cout << bfs() << endl;
      
   }
}
