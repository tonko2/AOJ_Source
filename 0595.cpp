#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
const int MAX = 1001;
const int MOD = 10007;

int main(){
   map<char,int>m;
   int N;
   string s;
   cin >> N >> s;
   m['J'] = 1, m['O'] = 2, m['I'] = 4;

   ll dp[MAX][1<<3];
   fill(dp[0],dp[MAX],0);
   dp[0][1] = 1;

   for(int i=0; i<N; i++){
      int value = m[s[i]];
      for(int j=0; j<(1<<3); j++){
         if(!(value & j))continue;
         for(int k=0; k<(1<<3); k++){
            if(!((j|value) & k))continue;
            dp[i+1][j|value] = (dp[i+1][j|value] + dp[i][k]) % MOD;
         }
      }
   }

   ll ans = 0;
   for(int i=0; i<(1<<3); i++) ans = (ans + dp[N][i]) % MOD;
   cout << ans << endl;

   
   return 0;
}
