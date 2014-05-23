#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int n,m,p,a,b;
double cost[31][31];
int ticket[11];
double d[31][(1<<10)];
bool used[31];

void dijkstra(int s){
   fill(d[0],d[m],INF);
   fill(used,used+m,false);
   for(int i=0; i<=n; i++) d[s][i] = 0;

   while(true){
      int v = -1;
      double mincost = INF;
      for(int i=0; i<m; i++){
         for(int j=0; j<1<<n; j++){
            if(!used[i] && (v == -1 || mincost > d[i][j])){
               mincost = d[i][j];
               v = i;
            }
         }
      }
      if(v == -1)break;
      used[v] = true;

      for(int i=0; i<m; i++){
         for(int j=0; j<1<<n; j++){
            for(int k=0; k<n; k++){
               //If ticket is used, executes continue
               if((j>>k & 1))continue;
               if(cost[v][i]!=INF)d[i][j+(1<<k)] = min(d[i][j+(1<<k)],d[v][j]+
                                    cost[v][i]/ticket[k]);
            }
         }
      }
   }

   double ans = 1<<29;
   for(int i=0; i<(1<<n); i++){
      ans = min(ans,d[b][i]);
   }
   
   if(ans == 1<<29) cout << "Impossible" << endl;
   else printf("%.3f\n",ans);
}

void init(){
   a--,b--;
   for(int i=0; i<n; i++) cin >> ticket[i];
   fill(cost[0],cost[m],INF);
   for(int i=0; i<p; i++){
      int from,to;
      double c;
      cin >> from >> to >> c;
      from--,to--;
      cost[from][to] = cost[to][from] = c;
   }
}

int main(){
   while(cin >> n >> m >> p >> a >> b,n|m|p|a|b){
      init();
      dijkstra(a);
   }
  return 0;
}
