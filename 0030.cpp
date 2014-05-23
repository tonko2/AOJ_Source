#include <iostream>
using namespace std;

int k,ans;

void dfs(int i,int sum,int n){
  if(sum == k && n == 0){
    ans++;
    return;
  }
  if(i == 10 || n == 0)return;
 
  dfs(i+1,sum,n);
  dfs(i+1,sum+i,n-1);
}

int main(){
  int n;
  while(cin >> n >> k){
    if(n == 0 && k == 0)break;
    ans = 0;
    dfs(0,0,n);
    cout << ans << endl;
  }
  return 0;
}
