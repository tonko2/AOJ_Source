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

const int MAX_V = 1000;

int V;
vector<int>G[MAX_V]; //グラフの隣接リスト表現
int match[MAX_V]; //マッチングのペア
bool used[MAX_V]; //DFSですでに調べたかのフラグ

void add_edge(int u, int v){
   G[u].push_back(v);
   G[v].push_back(u);
}

bool dfs(int v){
   used[v] = true;
   for(int i=0; i<G[v].size(); i++){
      int u = G[v][i], w = match[u];
      if(w < 0 || !used[w] && dfs(w)){
         match[v] = u;
         match[u] = v;
         return true;
      }
   }
   return false;
}

int bipartite_matching(){
   int res = 0;
   memset(match, -1, sizeof(match));

   for(int v=0; v<V; v++){
      if(match[v] < 0){
         memset(used,0,sizeof(used));
         if(dfs(v)){
            res++;
         }
      }
   }
   return res;
}

int gcd(int a, int b){
   if(b == 0) return a;
   return gcd(b,a%b);
}

int main(){
   int n,m;
   while(cin >> m >> n,m|n){
      int b[m], r[n];
      for(int i=0; i<m+n; i++) G[i].clear();
      for(int i=0; i<m; i++) cin >> b[i];
      for(int i=0; i<n; i++) cin >> r[i];

      for(int i=0; i<m; i++){
         for(int j=0; j<n; j++){
            if(gcd(b[i],r[j]) != 1) add_edge(i,j+m);
         }
      }

      V = max(m,n);
      cout << bipartite_matching() << endl;
   }
  return 0;
}
