#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class State{
public:
   int to,cost,ticket;
   State(int to, int cost, int ticket) : to(to), cost(cost), ticket(ticket) {}
   State(){}
   
   bool operator < (const State &s) const{
      return cost > s.cost;
   }   
};

vector<State>v[100];
bool used[100][11];
int dijkstra(int d,int s, int c){

   priority_queue<State>que;
   que.push(State(s,0,c));
   fill(used[0],used[100],false);
   while(!que.empty()){
      State tmp = que.top(); que.pop();
      int t = tmp.to;

      if(!used[t][tmp.ticket]) used[t][tmp.ticket] = true;
      else continue;
      
      if(tmp.to == d) return tmp.cost;
      for(int i=0; i<(int)v[t].size(); i++){
         if(tmp.ticket > 0){
         que.push(State(v[t][i].to,v[t][i].cost/2+tmp.cost,tmp.ticket-1));
         }
         que.push(State(v[t][i].to,v[t][i].cost+tmp.cost,tmp.ticket));
      }
   }
}

int main(){
   int c,n,m,s,d;
   while(cin >> c >> n >> m >> s >> d,c|n|m|s|d){
      s--,d--;
      for(int i=0; i<100; i++) v[i].clear();
      for(int i=0; i<m; i++){
         int in1,in2,in3;
         cin >> in1 >> in2 >> in3;
         in1--,in2--;
         v[in1].push_back(State(in2,in3,c));
         v[in2].push_back(State(in1,in3,c));
      }
      cout << dijkstra(d,s,c) << endl;
      
   }
   return 0;
}
