#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int n;
   ll a[101];
   ll dp[101][21];
   ll ans = 0;
   bool flag = false;
   cin >> n;
   for(int i=0; i<n; i++) cin >> a[i];
   fill(dp[0],dp[101],0);
   dp[0][a[0]] = 1;
   for(int i=1; i<n-1; i++){
      for(int j=0; j<=20; j++){
         if(j-a[i] >= 0) dp[i][j] += dp[i-1][j-a[i]];
         if(j+a[i] <= 20) dp[i][j] += dp[i-1][j+a[i]];
      }
   }
   
   ans = dp[n-2][a[n-1]];
   cout << ans << endl;
  return 0;
}
