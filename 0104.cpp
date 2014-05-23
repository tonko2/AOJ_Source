#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100;
const int INF = 1000000;
const char l[] = {"^>v<"};
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
int N,M,sx=0,sy=0,d[MAX_N][MAX_N];
char field[MAX_N][MAX_N];

void bfs(){
  queue<pair<int,int> >Q;

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)d[i][j] = INF;

  Q.push(pair<int,int>(sx,sy));
  d[sx][sy] = 0;
  pair<int,int>p;
  while(!Q.empty()){
    p = Q.front();
    Q.pop();

    for(int i=0; i<4; i++){
      if(field[p.first][p.second] == l[i]){
	int nx = p.first + dx[i], ny = p.second + dy[i];
	if(nx >= 0 && N > nx && ny >= 0 && M > ny && d[nx][ny] == INF){
	  Q.push(pair<int,int>(nx,ny));
	  d[nx][ny] = d[p.first][p.second]+1;
	}
	else if(nx >= 0 && N > nx && ny >= 0 && M > ny && d[nx][ny] != INF){
	  cout << "LOOP" << endl;
	  return;
	}
      }
      if(field[p.first][p.second] == '.'){
	cout << p.second << ' ' << p.first << endl;
	return;
      }
    }
  }
} 


int main(){
  while(cin >> N >> M && (N || M)){
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)cin >> field[i][j];
    bfs();
  }
  return 0;
}  
