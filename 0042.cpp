#include <iostream>
using namespace std;

const int MAX = 1000;
int v[MAX],w[MAX];
int W,n;
int dp[MAX+1][MAX+1];

void solve(){
  int weight = 0;
  fill(dp[0],dp[MAX],0);
  
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=W; j++){
      if(j<w[i]) dp[i][j] = dp[i+1][j];
      else dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
    }
  }
  cout << dp[0][W] << endl;
  int value = dp[0][W];
  for(int i=0; i<=W; i++){
    if(dp[0][i] == value){
      weight = i;
      break;
    }
  }
  cout << weight << endl;
}
int main(){
  char c;
  int count = 0;
  while(cin >> W && W){
  cin >> n;
  for(int i=0; i<n; i++) cin >> v[i] >> c >> w[i];

  cout << "Case " << ++count << ':' << endl;
  solve();
  }
  return 0;
}
