#include <iostream>
#include <algorithm>
using namespace std;

int r,c,bit[10][10000],ans;

void solve(){
  int ans = 0;
  for(int i=0; i<(1<<r); i++){ 
    int sum = 0;
    for(int j=0; j<c; j++){
      int sum1 = 0;
      for(int k=0; k<r; k++){
	if((1<<k) & i)
	  sum1 += 1 - bit[k][j];
	else
	  sum1 += bit[k][j];
      }
      sum += max(sum1,r-sum1);
    }
    ans = max(ans,sum);
  }
  cout << ans << endl;
}

int main(){
  while(cin >> r >> c && (r || c)){
    for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
	cin >> bit[i][j];
    solve();
  }
  return 0;
}
