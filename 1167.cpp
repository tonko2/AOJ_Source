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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int INF = 1<<29;
const int MAX = 1000000;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int dp[MAX],dp2[MAX];
int main(){

   vector<int>v,v2;
   for(int i=1; i<=200; i++){
      v.push_back(i*(i+1)*(i+2)/6);
      if((i*(i+1)*(i+2)/6) % 2 != 0) v2.push_back(i*(i+1)*(i+2)/6);
   }
   
   fill(dp,dp+MAX,INF);
   fill(dp2,dp2+MAX,INF);
   dp[0] = dp2[0] = 0;
   
   for(int i=0; i<v.size(); i++)
      for(int j=v[i]; j<MAX; j++)
         dp[j] = min(dp[j],dp[j-v[i]]+1);
   

   for(int i=0; i<v2.size(); i++)
      for(int j=v2[i]; j<MAX; j++)
         dp2[j] = min(dp2[j],dp2[j-v2[i]]+1);

   int n;
   while(cin >> n && n){
      cout << dp[n] << " " << dp2[n] << endl;
   }
   return 0;
}
