#include <iostream>
#include <algorithm>
using namespace std;

int n,data[20],ans;

void dfs(int tc, int A, int B){
   if(tc == n){
      ans = min(ans,abs(A-B));
      return;
   }
   dfs(tc+1,A+data[tc],B);
   dfs(tc+1,A,B+data[tc]);
}
int main(){
   while(cin >> n && n){
      ans = 100000000;
      for(int i=0; i<n; i++) cin >> data[i];
      dfs(0,0,0);
      cout << ans << endl;
   }
   return 0;
}
