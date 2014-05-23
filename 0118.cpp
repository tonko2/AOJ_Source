#include <iostream>
using namespace std;

const int MAX = 110;
const int INF = 1000000;
int n,m;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(int x, int y,char moji){
  visited[x][y] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i], ny = y + dy[i];
    if(nx >= 0 && n > nx && ny >= 0 && m > ny && visited[nx][ny] == 0 &&
       map[nx][ny] == moji){
      visited[nx][ny] = 1;
      dfs(nx,ny,moji);
    }
  }
  return;
}
int main(){
  while(cin >> n >> m && (n|m)){
    int cnt = 0;
    fill(visited[0],visited[MAX],false);
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++) cin >> map[i][j];

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	if(map[i][j] == '#' && !visited[i][j]){
	  cnt++;
	  dfs(i,j,'#');
	}
	else if(map[i][j] == '*' && !visited[i][j]){
	  cnt++;
	  dfs(i,j,'*');
	}
	else if(map[i][j] == '@' && !visited[i][j]){
	  cnt++;
	  dfs(i,j,'@');
	}
      }
    }

    cout << cnt << endl;
  }
  return 0;
}
