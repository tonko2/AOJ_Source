#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;
ll dp[10001];
int main() {
   int n, w;
   cin >> n >> w;
   int a[n];
   int sum = 0;
   for(int i=0; i<n; i++){
      cin >> a[i];
      sum += a[i];
   }
   sort(a, a+n, greater<int>());
   dp[0] = 1;
   ll ans = 0;
   if (sum <= w) ans = 1;
   for(int i=0; i<n; i++){         
      sum -= a[i];
      for (int j=max(0,w-sum-a[i]+1); j<=w-sum; ++j) {
         ans = (ans + dp[j]) % MOD;
      }
      for (int j=w-a[i]; j>=0; --j) {
         dp[j+a[i]] = (dp[j+a[i]] + dp[j]) % MOD;
      }
   }
   cout << ans << endl;
   return 0;
}
