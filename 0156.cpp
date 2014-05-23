#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int H,W;
int sx,sy;
typedef pair<int,int> P;
typedef pair<int,P>P2;
bool used[101][101];
string s[101];
int bfs(){
   fill(used[0],used[101],false);
   priority_queue<P2,vector<P2>,greater<P2> >que;
   que.push(P2(0,P(sx,sy)));

   while(!que.empty()){
      P2 p = que.top();
      que.pop();
      int cost = p.first;
      int x = p.second.first;
      int y = p.second.second;

      if(used[y][x])continue;
      if(y == H-1 || x == W-1 || y == 0 || x == 0) return cost;

      used[y][x] = true;

      for(int i=0; i<4; i++){
         int nx = x + dx[i], ny = y + dy[i];
         int c = 0;
         if(nx < 0 || ny < 0 || W <= nx || H <= ny)continue;
         if(s[y][x] == '.' && s[ny][nx] == '#') c = 1;
         que.push(P2(cost+c,P(nx,ny)));
      }
   }
   return -1;
}
int main(){

   while(cin >> W >> H,W|H){

      for(int i=0; i<H; i++) cin >> s[i];

      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            if(s[i][j] == '&'){
               sx = j, sy = i;
               s[i][j] = '.';
            }
         }
      }
      cout << bfs() << endl;
   }
   return 0;
}
