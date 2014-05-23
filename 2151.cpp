#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class State{
public:
   int b,d,e;
   State(){}
   State(int b, int d, int e):b(b),d(d),e(e){}

   bool operator < (const State& s) const {
      return e > s.e;
   }
};

vector<State> G[101];
int N,M,L;
bool used[101][101]; //N L
int dijkstra(int s){
   memset(used,0,sizeof(used));
   priority_queue<State> que;
   que.push(State(0,L,0));
   
   while(!que.empty()){
      State tmp = que.top();
      que.pop();
      
      if(tmp.b == N-1) return tmp.e;
      if(used[tmp.b][tmp.d])continue;
      used[tmp.b][tmp.d] = true;
      
      for(int i=0; i<G[tmp.b].size(); i++){
         State t = tmp;
         int to = G[tmp.b][i].b;
         int cost = G[tmp.b][i].d;
         int num = G[tmp.b][i].e;
         if(t.d - cost >= 0) que.push(State(to,t.d-cost,t.e));
         que.push(State(to,t.d,t.e+num));
      }
   }
}

int main(){
   while(cin >> N >> M >> L,N|M|L){
      for(int i=0; i<=100; i++) G[i].clear();
      for(int i=0; i<M; i++){
         int a,b,d,e;
         cin >> a >> b >> d >> e;
         a--,b--;
         G[a].push_back(State(b,d,e));
         G[b].push_back(State(a,d,e));
      }
      cout << dijkstra(0) << endl;
   }
  return 0;
}
