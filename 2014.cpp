#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

char field[50][50];
bool used[50][50];
int ansB,ansW;
int w,h;

void bfs(int sx, int sy){
//   cout << "sy = " << sy << " sx = " << sx << endl;
   used[sy][sx] = true;
   int c = 0,cnt = 1;
   queue<P>que;
   que.push(mp(sy,sx));
   while(!que.empty()){
      P p = que.front();
      que.pop();
      int x = p.second, y = p.first;

      for(int i=0; i<4; i++){
         int nx = x + dx[i], ny = y + dy[i];
         if(0 > nx || 0 > ny || ny >= h || nx >= w || used[ny][nx])continue;
         //       cout << "ny = " << ny << " nx = " << nx << endl;
         if(field[ny][nx] == 'B'){
            if(c == 2) c = 3;
            else if(c == 0) c = 1;
         } else if(field[ny][nx] == 'W'){
            if(c == 1) c = 3;
            else if(c == 0) c = 2;
         } else {
            cnt++;
            used[ny][nx] = true;
            que.push(mp(ny,nx));
         }
      }
   }
   if(c == 1) ansB += cnt;
   else if(c == 2) ansW += cnt;
}
int main(){
   while(cin >> w >> h,w|h){
      fill(used[0],used[50],false);
      for(int i=0; i<h; i++)
         for(int j=0; j<w; j++) cin >> field[i][j];

      ansB = ansW = 0;
      for(int i=0; i<h; i++){
         for(int j=0; j<w; j++){
            if(used[i][j] || field[i][j] != '.')continue;
            bfs(j,i);
         }
      }
      cout << ansB << " " << ansW << endl;
   }
  return 0;
}
