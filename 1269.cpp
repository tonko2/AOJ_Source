#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)

vector<int>prime;
bool isPrime(int n){
   if(n == 0 || n == 1)return false;
   for(int i=2; i*i<=n; i++){
      if(n % i == 0) return false;
   }
   return true;
}

int main(){

   rep(i,1121){
      if(!isPrime(i))continue;
      prime.push_back(i);
   }


   int dp[20][2000];
   fill(dp[0],dp[20],0);
   dp[0][0] = 1;
   
   for(int i=0; i<prime.size(); i++){
      for(int j=1200; j>=prime[i]; j--){
         for(int k=15; k>=0; k--){
            if(j-prime[i] < 0)continue;
            dp[k][j] += dp[k-1][j-prime[i]];
         }
      }
   }
   
   int n,k;   
   while(cin >> n >> k,n|k){
      cout << dp[k][n] << endl;
   }



   
   return 0;
}
