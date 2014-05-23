#include <iostream>
using namespace std;

const int MAX_N = 100;
int n,m,a[MAX_N][MAX_N+1];

void dfs(int x, int y){
  a[x][y] = 0;

  for(int i=-1; i<=1; i++){
    for(int j=-1; j<=1; j++){
      int nx = x+i;
      int ny = y+j;
      if(0<=nx && nx<m && 0<=ny && ny<n && a[nx][ny] == 1)dfs(nx,ny);
    }
  }
  return;
}

int main(){
  while(cin >> n >> m){
    int ans=0;
    if(n == 0 && m == 0)break;
    
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
	cin >> a[i][j];
      }
    }
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
	if(a[i][j] == 1){
    dfs(i,j);
    ans++;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}

