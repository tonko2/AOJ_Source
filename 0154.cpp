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
   int n,m;
   while(cin >> n && n){
      int dp[1001];
      memset(dp,0,sizeof(dp));
//      dp[0] = 1;
      pair<int,int>p[n];
      for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;

      dp[0] = 1;
         for(int i=0; i<n; i++){
            for(int j=1000; j>=0; j--){
               for(int k=p[i].first; k<=p[i].first*p[i].second; k+=p[i].first){
                  if(j + k > 1000)continue;
                  dp[j+k] += dp[j];
               }
            }
         }
      
      cin >> m;
      for(int i=0; i<m; i++){
         int in;
         cin >> in;
         cout << dp[in] << endl;
      }
      
   }
  return 0;
}
