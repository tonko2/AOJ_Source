#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <cctype>
#include <math.h>

#define mp make_pair

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class State{
public:
   int x,y,cost,dir;
   State(int x, int y, int cost, int dir):x(x),y(y),cost(cost),dir(dir){}
   bool operator < (const State &s) const {
      return cost > s.cost;
   }
};

int w,h;
P goal;
vector<vector<int> >field;
int c[4];

int bfs(){
   priority_queue<State>que;
//   queue<State>que;
   que.push(State(0,0,0,0));
   bool used[4][40][40];
   memset(used,0,sizeof(used));
   while(!que.empty()){
      State tmp = que.top();
//      State tmp = que.front();
      que.pop();
      int x = tmp.x;
      int y = tmp.y;
      int d = tmp.dir;
      if(used[d][y][x])continue;
      used[d][y][x] = true;
      if(tmp.y == goal.first && tmp.x == goal.second) return tmp.cost;

      for(int i=0; i<4; i++){
         int nd = (tmp.dir+i) % 4;
         int nc = tmp.cost;
         if(field[y][x] != i){
            nc += c[i];
         }
         int nx = x + dx[nd], ny = y + dy[nd];
         if(nx < 0 || ny < 0 || nx >= w || ny >= h || used[nd][ny][nx])continue;
         que.push(State(nx,ny,nc,nd));
      }
   }
   return INF;
}
int main(){
   field.resize(40,vector<int>(40));
   while(cin >> w >> h,w|h){
      goal = P(h-1,w-1);

      
      for(int i=0; i<h; i++)
         for(int j=0; j<w; j++) cin >> field[i][j];


      
      for(int i=0; i<4; i++) cin >> c[i];
      
      cout << bfs() << endl;
     
   }
  return 0;
}
