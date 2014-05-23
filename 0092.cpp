#include <iostream>
using namespace std;

const int MAX = 1000;

int main(){
  int n,W[MAX][MAX];
  char G[MAX][MAX];

  while(cin >> n && n){
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) cin >> G[i][j];

    for(int i=0; i<n; i++){
      W[0][i] = (G[0][i] == '*')?0:1;
      W[i][0] = (G[i][0] == '*')?0:1;
    }

    int ans = 0;

    for(int i=1; i<n; i++){
      for(int j=1; j<n; j++){
	if(G[i][j] == '*') W[i][j] = 0;
	else{
	  W[i][j] = min(W[i-1][j-1],min(W[i][j-1],W[i-1][j])) + 1;
	  ans = max(ans,W[i][j]);
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
