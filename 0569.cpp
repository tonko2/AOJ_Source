#include <iostream>
using namespace std;

const int MAX = 102;
int w,h;
int d[MAX][MAX];
const int dx_odd[6] = {1,0,-1,0,1,1};
const int dy_odd[6] = {0,1,0,-1,-1,1};
const int dx_even[6] = {1,0,-1,0,-1,-1};
const int dy_even[6] = {0,1,0,-1,1,-1};

int dfs(int x, int y){
  d[y][x] = 2;
  int count = 0;
  for(int i=0; i<6; i++){
    int nx,ny;
    if(y % 2)
      nx = x + dx_odd[i], ny = y + dy_odd[i];
    else
      nx = x + dx_even[i], ny = y + dy_even[i];
    
    if(nx >= 0 && w+1 >= nx && ny >= 0 && h+1 >= ny){
      if(d[ny][nx] == 1){
	count++;
      }
      else if(d[ny][nx] == 0) count += dfs(nx,ny);
    }
  }
  return count;
}
int main(){
  cin >> w >> h;

  for(int i=1; i<=h; i++)
    for(int j=1; j<=w; j++) cin >> d[i][j];

  cout << dfs(0,0) << endl;

  return 0;
}
