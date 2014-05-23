#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

const int MAX = 1001;
const int INF = 1 << 29;

struct edge{
   int from, x,y;
};

double d[MAX];
edge E[MAX];
int prev[MAX];
double cost[MAX][MAX];
int V;
bool used[MAX];

vector<int> get_path(int t){
   vector<int>path;
   for(; t != -1; t = prev[t]){
      path.push_back(t);
   }
   reverse(path.begin(),path.end());
   return path;
}

void dijkstra(int s){
   fill(prev,prev+MAX,-1);
   fill(used,used+MAX,false);
   fill(d,d+MAX,INF);
   d[s] = 0;

   while(true){
      int v = -1;
      for(int i=1; i<=V; i++){
         if(!used[i] && (v == -1 || d[i] < d[v]) ) v = i;
      }
      if(v == -1)break;
      used[v] = true;

      for(int i=1; i<=V; i++){
         if(d[i] > d[v] + cost[v][i] && cost[v][i] <= 50){
            d[i] = d[v] + cost[v][i];
            prev[i] = v;
         }
      }
   }
}

int main(){
   while(cin >> V && V){
      fill(cost[0],cost[MAX],INF);
      for(int i=0; i<V; i++) cin >> E[i].from >> E[i].x >> E[i].y;
      
      for(int i=0; i<V; i++){
         for(int j=i+1; j<V; j++){
            double dis = sqrt(pow((E[i].x-E[j].x),2) + pow((E[i].y-E[j].y),2));
            cost[E[i].from][E[j].from] = dis;
            cost[E[j].from][E[i].from] = dis;
         }
      }
   
      int n;
      cin >> n;
      for(int i=0; i<n; i++){
         int s,e;
         cin >> s >> e;
         dijkstra(s);
         if(d[e] == INF) cout << "NA" << endl;
         else {
            vector<int>ans = get_path(e);
            for(int i=0; i<ans.size(); i++){
               if(i == 0) cout << ans[i];
               else cout << " " << ans[i];
            }
            cout << endl;
         }
      }
   }
   return 0;
}
