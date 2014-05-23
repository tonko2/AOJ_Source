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
#include <math.h>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 200001;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int y[MAX];
int C[17];
int a[MAX];
int ans,N,m;

void dfs(int n, int cost){
   if(n == N){
      ans = min(ans,cost);
      return;
   }

   for(int i=0; i<m; i++){
      y[n+1] = y[n] + C[i];
      if(y[n+1] > 255) y[n+1] = 255;
      if(y[n+1] < 0) y[n+1] = 0;
      dfs(n+1,cost + pow(a[n]-y[n+1],2.0));
   }
}
int main(){
   y[0] = 128;
   int n;
   while(cin >> n >> m,n|m){
      ans = 1<<29;
      N = n;
      for(int i=0; i<m; i++){
         cin >> C[i];
      }

      for(int i=0; i<n; i++) cin >> a[i];

      dfs(0,0);

      cout << ans << endl;
   }

  return 0;
}
