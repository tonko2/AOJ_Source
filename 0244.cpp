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

const int MAX = 100;

class State{
public:
   int to,cost,ticket;
   State(int to, int cost, int ticket):to(to),cost(cost),ticket(ticket){}
   State(){}
   bool operator < (const State &s) const{
      return cost > s.cost;
   }
};

vector<State>v[100];
bool used[100][2];

int dijkstra(int e){
   priority_queue<State> que;
   que.push(State(0,0,1));
   fill(used[0],used[100],false);
   while(!que.empty()){
      State tmp = que.top(); que.pop();
      int t = tmp.to;
      if(!used[t][tmp.ticket]) used[t][tmp.ticket] = true;
      else continue;
      if(t == e) return tmp.cost;
      for(int i=0; i<v[t].size(); i++){
         que.push(State(v[t][i].to,v[t][i].cost+tmp.cost,tmp.ticket));
         if(tmp.ticket){
            int to = v[t][i].to;
            for(int j=0; j<v[to].size(); j++){
               if(v[to][j].to == tmp.to) continue;
               que.push(State(v[to][j].to,tmp.cost,tmp.ticket-1));
            }
         }
      }
   }
}
int main(){
   int n,m,a,b,c,s,e;
   while(cin >> n >> m,n|m){
      s = 0, e = --n;
      for(int i=0; i<100; i++) v[i].clear();
      for(int i=0; i<m; i++){
         cin >> a >> b >> c;
         a--,b--;
         v[a].push_back(State(b,c,1));
         v[b].push_back(State(a,c,1));
      }
      cout << dijkstra(e) << endl;
   }
  return 0;
}
