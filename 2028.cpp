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
#include <cctype>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int n;
   cin >> n;
   for(int t=0; t<n; t++){
      int in;
      cin >> in;
      int a[101];
      P dp[101][101];
      for(int i=0; i<in; i++){
         cin >> a[i];
      }
      for(int i=0; i<=100; i++)
         for(int j=0; j<=100; j++) dp[i][j].first = dp[i][j].second = 0;

      for(int i=1; i<=in; i++){
         for(int j=0; j<in; j++){
            for(int k=(j+1)%in; k<in; k++){
               if(k-j>1)continue;
               if(j == in-1 && k>0)break;
               if(dp[i][k].first<dp[i-1][k].first+abs(a[dp[i-1][j].second]-a[k])){
                  dp[i][k].first = dp[i-1][k].first+abs(a[dp[i-1][j].second]-a[k]);
                  dp[i][k].second = dp[i-1][j].second;
               }
            }
         }
      }

      int ans = 0;
      for(int i=0; i<in; i++)
         ans = max(ans,dp[in-2][i].first);
      cout << ans << endl;
   }
  return 0;
}
