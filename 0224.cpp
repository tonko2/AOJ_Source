#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

const int INF = 1<<29;
const int MAX = 200;

struct Edge{
   int from,to,cost;
   Edge(){}
   Edge(int from, int to, int cost):from(from),to(to),cost(cost){}
};

vector<Edge>G;
int M,n,k,D;
int cal[6];
int d[1<<6][MAX];

void bellman_ford(int s){
   while(1){
      bool update = false;
      for(int i=0; i<G.size(); i++){
         Edge e = G[i];
//         cout << "from = " << e.from << " to = " << e.to << " cost = " << e.cost << endl;
         for(int j=0; j<(1<<M); j++){
            if(e.to < M && (j & (1<<e.to)))continue;
            if(e.to < M){
               if(d[j|(1<<e.to)][e.to] > d[j][e.from] + e.cost - cal[e.to]){
                  d[j|(1<<e.to)][e.to] = d[j][e.from] + e.cost - cal[e.to];
                  update = true;
               }
            } else {
               if(d[j][e.to] > d[j][e.from] + e.cost){
                  d[j][e.to] = d[j][e.from] + e.cost;
                  update = true;
               }
            }
         }
      }
      if(!update)break;
   }
}
int main(int argc, char *argv[])
{
   while(cin >> M >> n >> k >> D,M|n|k|D){
      fill(cal,cal+6,0);
      for(int i=0; i<M; i++) cin >> cal[i];
      G.clear();
      map<string,int>m;
      m["H"] = n+M;
      m["D"] = n+M+1;

      int cnt = 0;
      for(int i=1; i<=M; i++){
         string s = "C";
         s += (i+'0');
         m[s] = cnt++;
      }
      for(int i=1; i<=n; i++){
         string s = "L";
         ostringstream oss;
         oss << s << i;
         m[oss.str()] = cnt++;
      }

      for(int i=0; i<D; i++){
         string f,t;
         int from,to,c;
         cin >> f >> t >> c;
         from = m[f];
         to = m[t];
         G.push_back(Edge(from,to,c*k));
         G.push_back(Edge(to,from,c*k));
//         cout << "from = " << from << " to = " << to << " c = " << c*k << endl;
      }

      for(int i=0; i<(1<<6); i++)
         for(int j=0; j<MAX; j++) d[i][j] = INF;
      
      d[0][n+M] = 0;
      bellman_ford(n+M);

      int ans = 1<<29;
      for(int i=0; i<(1<<M); i++) ans = min(ans,d[i][n+M+1]);
      cout << ans << endl;
      
   }
   return 0;
}
