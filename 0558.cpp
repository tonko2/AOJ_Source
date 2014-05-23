#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int INF = 100000000;

char maze[MAX_N][MAX_N+1];

int H,W,N;

int sx,sy;
int gx,gy;

int d[MAX_N][MAX_N];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(){
  queue<pair<int,int> >que;
  
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      d[i][j] = INF;
  
  
  que.push(pair<int,int>(sx,sy));
  d[sx][sy] = 0;
  
  while(que.size()){
    pair<int,int>p;
    p = que.front();
    que.pop();
    
    if(p.first == gx && p.second == gy)break;
    
    for(int i=0; i<4; i++){
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      
      if(0 <= nx && nx < H && 0 <= ny && ny < W && maze[nx][ny] != 'X' &&
	 d[nx][ny] == INF){
	que.push(pair<int,int>(nx,ny));
	d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}


void solve(){
  int res = 0;
  res += bfs();
  for(int i=1; i<N; i++){
    for(int j=0; j<H; j++){
      for(int k=0; k<W; k++){
	if(maze[j][k] - '0' == i){
	  sx = j;
	  sy = k;
	}
	if(maze[j][k] - '0' == i+1){
	  gx = j;
	  gy = k;
	}
      }
    }
    res += bfs();
  }
  cout << res << endl;
}
int main(){

  while(cin >> H >> W >> N){

    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++)
	cin >> maze[i][j];

    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
	if(maze[i][j] == 'S'){
	  sx = i;
	  sy = j;
	}
	if(maze[i][j] - '0' == 1){
	  gx = i;
	  gy = j;
	}
      }
    } 
    solve();
  }
  return 0;
}
