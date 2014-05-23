#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int dp[101][4][4];
int data[101];

main(){
  dp[0][0][0] = 1;
  cin >> n >> k;
  for(int i=0;i<k;i++){
    int in;
    cin >> in;
    cin >> data[in];
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        if(data[i] != 0){
          if(j == k && j == data[i])continue;
	  else{
            dp[i][k][data[i]] += dp[i-1][j][k];
            dp[i][k][data[i]] %= 10000;
          }
        }else{
          for(int l=1;l<4;l++){
            if(j == k && j == l)continue;
              else{
              dp[i][k][l] += dp[i-1][j][k];
              dp[i][k][l] %= 10000;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      ans += dp[n][i][j];
      ans %= 10000;
    }
  }
  cout << ans << endl;
  return 0;
}
