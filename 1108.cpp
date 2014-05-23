#include <iostream>
#include <vector>
using namespace std;

struct edge{
  int to,cost,id;
  edge(int to, int cost, int id) : to(to), cost(cost), id(id) {}
};

const int MAX_V = 11;
const int MAX_E = 22;

int V,E;
vector<edge> v[MAX_V];
vector<int>v2;
vector<int>path;
bool visited[MAX_V];
int ans;

void dfs(int prev, int cost){
  v2.push_back(prev);
  bool flag = false;
  for(int i=0; i<v[prev].size(); i++){
    if(visited[v[prev][i].id]) continue;
    visited[v[prev][i].id] = true;
    dfs(v[prev][i].to,v[prev][i].cost + cost);
    visited[v[prev][i].id] = false;
    flag = true;
  }

  if(!flag){
    if(cost > ans){
      ans = cost;
      path = v2;
    }
  }
  v2.pop_back();
}

int main(){
  while(cin >> V >> E && (V|E)){
    for(int i=0; i<MAX_V; i++)v[i].clear();
    //    v.clear();
    ans = 0;
    for(int i=0; i<E; i++){
      int f,t,c;
      cin >> f >> t >> c;
      v[f].push_back(edge(t,c,i));
      v[t].push_back(edge(c,t,i));
    }

    for(int i=0; i<V; i++){
      fill(visited,visited+MAX_V,0);
      dfs(i,0);
    }

    cout << ans << endl;
    for(int i=0; i<v2.size(); i++){
      if(i != 0) cout << ' ';
      cout << v2[i] + 1;
    }
    cout << endl;
  }
  return 0;
}
