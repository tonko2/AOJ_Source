#include <iostream>
#include <queue>
using namespace std;

int N,X,Y,sx,sy;
string maze[8];
int dx[12] = {-1,-2,-3,0,0,0,1,2,3,0,0,0};
int dy[12] = {0,0,0,-1,-2,-3,0,0,0,1,2,3};

void bfs(){
  queue<pair<int,int> >Q;

  Q.push(pair<int,int>(sx,sy));
  maze[sx][sy] = '0';
  while(!Q.empty()){
    pair<int,int>p;
    p = Q.front();
    Q.pop();

    for(int i=0; i<12; i++){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx >= 0 && 8 > nx && ny >= 0 && 8 > ny && maze[nx][ny] == '1'){
	maze[nx][ny] = '0';
	Q.push(pair<int,int>(nx,ny));
      }
    }
  }
  return;
}
int main(){
  int count = 0;
  cin >> N;
  for(int i=0; i<N; i++){

    for(int j=0; j<8; j++) cin >> maze[j];
    cin >> X >> Y;
    sx = Y-1, sy = X-1;
    bfs();
    cout << "Data " << ++count << ":" << endl;
    for(int j=0; j<8; j++){
      for(int k=0; k<8; k++){
	cout << maze[j][k];
      }
      cout << endl;
    }
  }
  return 0;
}
