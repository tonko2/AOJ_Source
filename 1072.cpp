#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
int r,c;
vector<vector<int> >v(MAX,vector<int>(MAX+1));
int pos[MAX+1][MAX+1];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int main(){
  
  while(cin >> r >> c && (r||c)){
    v.clear();  
  
    fill(pos[0],pos[MAX+1],1);

    int count = 0;

    for(int i=1; i<=r; i++)
      for(int j=1; j<=c; j++)
	v[i][j] = ++count;

    for(int i=1; i<=r; i++){
      for(int j=1; j<=c; j++){
	for(int k=0; k<4; k++){
	  int nx = i + dx[k], ny = j + dy[k];
	  if(nx >= 1 && r+1 > nx && ny >= 1 && c+1 > ny && pos[nx][ny] == 1 &&
	     pos[i][j] == 1){
	    pos[nx][ny] = 0;
	    pos[i][j] = 0;
	    swap(v[i][j],v[nx][ny]);
	  }
	}
      }
    }
    bool flag = false;
    for(int i=1; i<=r; i++){
      for(int j=1; j<=c; j++){
	if(pos[i][j] == 1) flag = true;
      }
    }
    if(!flag)
      cout << "yes" << endl;
    else
      cout << "no" << endl;

  }
    return 0;
}
