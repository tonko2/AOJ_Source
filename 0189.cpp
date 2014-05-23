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


const int INF = 1 << 29;
const int MAX = 60;
int cost[MAX][MAX];
int n;
void warshall_floyd(){
   for(int k=0; k<10; k++)
      for(int i=0; i<10; i++)
         for(int j=0; j<10; j++)
            cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
}
int main(){
   while(cin >> n && n){
      fill(cost[0],cost[MAX],INF);
      for(int i=0; i<n; i++){
         int f,t,c;
         cin >> f >> t >> c;
         cost[f][t] = c;
         cost[t][f] = c;
      }
      warshall_floyd();
      int ans = INF;
      int ans2 = 0;
      for(int i=0; i<10; i++){
         int res = 0;
         for(int j=0; j<10; j++){
            if(cost[i][j] == INF) continue;
            if(i == j) continue;
            res += cost[i][j];
         }
         if(res == 0) continue;
         if(ans > res){
            ans = res;
            ans2 = i;
         }
      }
      cout << ans2 << " " << ans << endl;
   }
  return 0;
}
