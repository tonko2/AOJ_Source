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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int field[22][22];
int w,h,sx,sy,gx,gy,ans;

void dfs(int cnt, int x, int y){
   if(x == gx && y == gy){
      ans = min(ans,cnt);
      return;
   }
   if(cnt >= 10 || cnt >= ans)return;
   for(int i=0; i<4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      while(1){
         if(field[ny][nx] != 0)break;
         nx += dx[i], ny += dy[i];
      }
      if(field[ny][nx] == 3){
         dfs(cnt+1,nx,ny);
      }
      else if(nx == x + dx[i] && ny == y + dy[i]) continue;
      else if(field[ny][nx] == -1) continue;
      else if(field[ny][nx] == 1){
          field[ny][nx] = 0;         
          dfs(cnt+1,nx-dx[i],ny-dy[i]);
          field[ny][nx] = 1;
       } 
   }
}
int main(){
   while(cin >> w >> h && w && h){
      ans = 1 << 29;
      for(int i=0; i<22; i++){
         for(int j=0; j<22; j++){
            field[i][j] = -1;
         }
      }
      
      for(int i=1; i<=h; i++){
         for(int j=1; j<=w; j++){
            int in;
            cin >> in;
            field[i][j] = in;
            if(in == 2) sx = j, sy = i,field[i][j] = 0;
            if(in == 3) gx = j, gy = i;
         }
      }
      dfs(0,sx,sy);
      if(ans == 1 << 29 || ans > 10) cout << -1 << endl;
      else cout << ans << endl;
   }
   
  return 0;
}
