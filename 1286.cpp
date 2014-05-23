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
const int MAX = 100001;
const int INF = 1<<29;

using namespace std;


typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
vector<vector<double> >memo;

double dfs(int total,int N){
   if(memo[N][total] != -1) return memo[N][total];
   if(N == n){
      if(total - k > 0) return total-k;
      return 1;
   }

   double res = 0;
   for(int i=1; i<=m; i++){
      res += dfs(total+i,N+1);
   }
   
   res /= m;

//   cout << "N = " << N << " total = " << total << endl;
//   cout << "res = " << res << endl;
   
   return memo[N][total] = res;
}

int main(){
   while(cin >> n >> m >> k,n|m|k){
      memo.clear();
      memo.resize(n+1,vector<double>(n*m+1));
      for(int i=0; i<=n; i++)
         for(int j=0;j <=n*m; j++) memo[i][j] = -1;
      double ans = dfs(0,0);
      printf("%.8f\n",ans);
   }
   
  return 0;
}
