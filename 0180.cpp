#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAX = 101;
const int INF = 1 << 29;
int n, m;
int cost[MAX][MAX];
int mincost[MAX];
bool used[MAX];
 
int prim(){
  fill(mincost, mincost+MAX, INF);
  memset(used, false, sizeof(used));
   
  mincost[0] = 0;
  int ans = 0;
   
  while(true){
    int v = -1;
    for(int i = 0 ; i < n ; i++){
      if(!used[i] && (v == -1 || mincost[i] < mincost[v])) v = i;
    }
     
    if(v == -1) break;
    used[v] = true;
    ans += mincost[v];
     
    for(int i = 0 ; i < n ; i++){
      mincost[i] = min(mincost[i], cost[v][i]);
    }
  }
  return ans;
}
     
int main(){
  while(cin >> n >> m){
    if(n == 0 && m == 0) break;
    fill(cost[0],cost[MAX],INF);
    int f,t,c;
    for(int i = 0 ; i < m ; i++){
       cin >> f >> t >> c;
       cost[f][t] = c;
       cost[t][f] = c;
    }
    cout << prim() << endl;
  }
  return 0;
}
