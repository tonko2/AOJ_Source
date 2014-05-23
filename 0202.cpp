#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int n,money,data[30],prime[MAX+1],ans,dp[MAX+1];

void eratos(){
  fill(prime,prime+MAX+1,1);
  prime[0] = prime[1] = 0;
  for(int i=2; i<sqrt(MAX); i++){
    for(int j=2*i; j<=MAX; j+=i){
      if(prime[j]) prime[j] = 0;
    }
  }
}

int main(){
  while(cin >> n >> money,(n|money)){
    int ans = 0;
    eratos();
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
      cin >> data[i];
      dp[data[i]] = 1;
    }
    sort(data,data+n);
    for(int i=0; i<=money; i++){
      for(int j=0; j<n; j++){
	if(i-data[j] >= 0 && dp[i-data[j]]){
	  dp[i] = 1;
	  break;
	}
      }
    }

    for(int i=money; i>=0; i--){
      if(dp[i] && prime[i]){
	ans = i;
	break;
      }
    }
    
    if(ans)cout << ans << endl;
    else cout << "NA" << endl;
  }
  return 0;
}
