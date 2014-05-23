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
const int MAX = 3001;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

struct Edge{
   int to,cost;
   Edge(int t, int c){
      to = t;
      cost = c;
   }
};

int main(){
   int n,m,k;
   cin >> n >> m >> k;
   vector<Edge>G[n];
   int d[n];
   for(int i=0; i<m; i++){
      int f,t,c;
      cin >> f >> t >> c;
      f--,t--;
      G[f].push_back(Edge(t,c));
      G[t].push_back(Edge(f,c));
   }

   vector<int>start;
   for(int i=0; i<k; i++){
      int s;
      cin >> s;
      s--;
      start.push_back(s);
   }

   double ans = 0;
   priority_queue<P,vector<P>,greater<P> >que;
   fill(d,d+n,INF);
   for(int t=0; t<start.size(); t++){
      int s = start[t];
      que.push(P(0,s));
      d[s] = 0;
   }
   while(!que.empty()){
      P p = que.top();
      que.pop();
      int from = p.second, cost = p.first;
      if(d[from] < cost)continue;

      for(int i=0; i<G[from].size(); i++){
         Edge e = G[from][i];
         if(d[e.to] > d[from] + e.cost){
            d[e.to] = d[from] + e.cost;
            que.push(P(d[e.to],e.to));
         }
      }
   }
   
   for(int i=0; i<n; i++){
      for(int j=0; j<G[i].size(); j++){
         Edge e = G[i][j];
         double c = (d[i] + d[e.to] + e.cost) / 2.0;
         ans = max(ans,c);
      }
   }
   
   printf("%.f\n",round(ans));
   return 0;
}
