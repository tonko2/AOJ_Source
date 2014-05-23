#include <iostream>
using namespace std;

int a,b,n,used[40][40],x,y,ans;
int dx[2] = {1,0};
int dy[2] = {0,1};
void dfs(int x, int y){
  if(x == a-1 && y == b-1)ans++;

  for(int i=0; i<2; i++){
    int nx = x + dx[i], ny = y + dy[i];
    if(0 <= nx && nx < a && 0 <= ny && ny < b &&
       !used[nx][ny]){
      dfs(nx,ny);
    }
  }
}

int main(){
  while(cin >> a >> b,(a|b)){
    fill(used[0],used[40],0);
    ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> x >> y;
      used[x-1][y-1] = 1;
    }

    dfs(0,0);
    cout << ans << endl;
  }
  return 0;
}
