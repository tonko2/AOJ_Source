#include <iostream>
using namespace std;

int N=12,M=12;
string field[12];
void dfs(int x, int y){
  field[x][y] = '0';

  pair<int,int>p[5];
  p[0].first = -1,p[0].second = 0;
  p[1].first = 0,p[1].second = -1;
  p[2].first = 0,p[2].second = 0;
  p[3].first = 0,p[3].second = 1;
  p[4].first = 1,p[4].second = 0;
  
  for(int i=0; i<5; i++){
    int nx = x + p[i].first, ny = y + p[i].second;
    if(nx >= 0 && N > nx && ny >= 0 && M > ny && field[nx][ny] == '1')
      dfs(nx,ny);
  }
  return;
}



int main(){
  while(1){
    for(int i=0; i<12; i++) cin >> field[i];
    if(cin.eof())return 0;   
    int res = 0;
    
    for(int i=0; i<12; i++){
      for(int j=0; j<12; j++){
	if(field[i][j] == '1'){
	  res++;
	  dfs(i,j);
	}
      }
    }
    cout << res << endl;
  }
  return 0;
}

