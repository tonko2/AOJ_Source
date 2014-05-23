#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

typedef pair<int,int> P;

class State{
public:
   int cost,color;
   int grid[8][8];

   State(){}
   State(int c, int c2, int g[8][8]){
      cost = c;
      color = c2;
      for(int i=0; i<8; i++)
         for(int j=0; j<8; j++) grid[i][j] = g[i][j];
   }
   
   bool operator < (State s) const {
      if(color == s.color) return cost < s.cost;
      else return color > s.color;
   }
};

int grid[8][8];
int tmp[8][8];
bool used[8][8];
int H,W,C;
vector<P>v;

void dfs(int x, int y, int color){
   used[y][x] = true;
   v.push_back(make_pair(x,y));
   for(int i=0; i<4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= W || ny >= H)continue;
      if(used[ny][nx])continue;
      if(tmp[ny][nx] != color)continue;
      dfs(nx,ny,color);
   }
}

int count(int color){
   fill(used[0],used[8],false);
   dfs(0,0,color);
   return v.size();
}

int main(){
   while(cin >> H >> W >> C,H|W|C){
      v.clear();
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            cin >> grid[i][j];
         }
      }

      priority_queue<State>que;
      State s;
      int ans = -1;
      s.cost = 0;
      s.color = 0;
      
      for(int i=0; i<H; i++)
         for(int j=0; j<W; j++) s.grid[i][j] = grid[i][j];
      
      que.push(s);
      int cnt = 0;
      while(!que.empty()){
         State p = que.top();
         que.pop();
         int cost = p.cost;
         int color = p.color;

         if(color == 5 && p.grid[0][0] == C){
            ans = cost;
            break;
         }

         if(color == 5) continue;
         
         v.clear();

         cnt++;
         for(int i=1; i<=6; i++){
            v.clear();
            for(int j=0; j<H; j++)
               for(int k=0; k<W; k++) tmp[j][k] = p.grid[j][k];

            int a = count(tmp[0][0]);

            for(int j=0; j<v.size(); j++) tmp[v[j].second][v[j].first] = i;
            
            v.clear();
            a = count(tmp[0][0]);
            que.push(State(a,p.color+1,tmp));
         }
      }
      
      cout << ans << endl;
   }
   return 0;
}
