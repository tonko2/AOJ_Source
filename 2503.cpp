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
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

struct Edge{
   int to,from,cost;
};
int V,E;
int d[401];
vector<Edge>v;

void bellman_ford(int s){
   fill(d,d+401,INF);
   d[s] = 0;

   while(true){
      bool update = false;
      for(int i=0; i<E; i++){
         Edge e = v[i];
         if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
            update = true;
         }
      }
      if(!update)break;
   }
}
int main(){
   cin >> V >> E;
   for(int i=0; i<E; i++){
      Edge a;
      cin >> a.from >> a.to>> a.cost;
      a.cost = -a.cost;
      v.push_back(a);
   }
   bellman_ford(0);
   cout << -d[V-1] << endl;
   
  return 0;
}
