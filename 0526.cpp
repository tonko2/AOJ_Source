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

const int MAX = 101;
const int INF = 1<<29;
int cost[MAX][MAX];
int dis[MAX];
bool visit[MAX];
int n,k;

void dijkstra(int s){
   for(int i=0; i<n; ++i){
      dis[i] = INF;
      visit[i] = false;
   }
   dis[s] = 0;

   while(true){
      int v = -1;
      for(int i=0; i<n; ++i){
         if(!visit[i] && (v == -1 || dis[v] > dis[i])) v = i;   
      }

      if(v == -1) break;
      visit[v] = true;

      for(int i=0; i<n; ++i){
         dis[i] = min(dis[i],dis[v] + cost[v][i]);
      }
   }
}

int main(){

   while(cin >> n >> k,n|k){
      
      for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            cost[i][j] = INF;
         }
      }

      for(int t=0; t<k; t++){
         int in,a,b,c,d,e;
         cin >> in;
         if(in == 0){
            cin >> a >> b;
            a--,b--;
            dijkstra(a);
            if(dis[b] == INF) cout << -1 << endl;
            else cout << dis[b] << endl;
         } else {
            cin >> c >> d >> e;
            c--,d--;
            cost[c][d] = min(cost[c][d],e);
            cost[d][c] = min(cost[d][c],e);
         }
      }
      
   }
   return 0;
}
