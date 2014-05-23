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

const int MAX = 101;
const int INF = 1<<29;
const double EPS = 1e-8;
using namespace std;


class State{
public:
   int x,y,foot,t;
   State(){}
   State(int x, int y, int foot, int t):x(x),y(y),foot(foot),t(t){}

   bool operator < (const State& s) const {
      return t > s.t;
   }
};


int dx[2][9] = {{1,1,1,1,1,2,2,2,3},
                {-1,-1,-1,-1,-1,-2,-2,-2,-3}};

int dy[2][9] = {{-2,-1,0,1,2,-1,0,1,0},
                {-2,-1,0,1,2,-1,0,1,0}};



bool used[MAX][MAX][2];
char field[MAX][MAX];
int H,W,ans;

int dijkstra(int x, int y, int foot){
   memset(used,0,sizeof(used));
   priority_queue<State>que;
   que.push(State(x,y,foot,0));

   while(!que.empty()){
      State tmp = que.top();
      que.pop();

      int x = tmp.x, y = tmp.y;

      if(field[y][x] == 'T') return tmp.t;
      if(used[y][x][tmp.foot]) continue;
      used[y][x][tmp.foot] = true;
//      cout << "x = " << x << " y = " << y << " foot = " << tmp.foot << " time = " << tmp.t << endl;
      for(int i=0; i<9; i++){
         State t = tmp;
         int nx = x + dx[tmp.foot][i];
         int ny = y + dy[tmp.foot][i];
         if(nx < 0 || ny < 0 || nx >= W || ny >= H || field[ny][nx] == 'X')continue;
         if(field[ny][nx] >= '1' && field[ny][nx] <= '9'){
            t.t += field[ny][nx] - '0';
         }
         que.push(State(nx,ny,1-tmp.foot,t.t));
      }
   }
   return INF;
}

int main(){
   while(cin >> W >> H,W|H){
      for(int i=0; i<H; i++)
         for(int j=0; j<W; j++) cin >> field[i][j];

      ans = INF;
      for(int i=0; i<W; i++){
         for(int j=0; j<=1; j++){
            if(field[H-1][i] == 'S'){
               ans = min(ans,dijkstra(i,H-1,j));
            }
         }
      }
      cout << ((ans==INF)?-1:ans) << endl;
   }
  return 0;
}
