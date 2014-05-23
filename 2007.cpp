#include <iostream>
using namespace std;

const int C[] = {500,100,50,10};
int a[4];
int sumCoin,n,minCoin,Sum;
int ans[4],tmp[4];

int getChange(int k){
   int res = 0;
   for(int i=0; i<4; i++){
      res += k / C[i];
      k %= C[i];
   }
   return res;
}

void dfs(int c, int d, int sum){
   if(c == 4){
      if(sum < n) return;

      int coin = getChange(sum-n)-d;
      if(coin < minCoin){
         minCoin = coin;
         Sum = sum;
         for(int i=0; i<4; i++){
            ans[i] = tmp[i];
         }
      }
   } else {
      
      for(int i=0; i<=a[c]; i++){
         tmp[c] = i;
         dfs(c+1,d+i,sum+C[c]*i);   
      }
      
   }
}

int main(){
   bool flag = false;
   while(cin >> n && n){
      if(flag) cout << endl;
      flag = true;
      for(int i=0; i<4; i++) cin >> a[3-i];
      for(int i=0; i<4; i++) sumCoin += a[i];

      minCoin = Sum = 1<<29;
      dfs(0,0,0);

      for(int i=0; i<4; i++){
         if(ans[3-i]) cout << C[3-i] << " " << ans[3-i] << endl;
      }
   }
   return 0;
}
