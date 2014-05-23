#include <iostream>
#include <vector>
using namespace std;

struct edge{
  int from,to,cost,time;
};

const int INF = 100000000;
vector<edge>v;
int n,m,k,p,q,r,c[301],t[301];
edge ed;

void shortest_path(int f,int to, bool value){
  for(int i=1; i<=m; i++){
    c[i] = INF, t[i] = INF;
  }
  if(!value){
    c[f] = 0;
    while(true){
      bool update = false;
      for(int i=0; i<v.size(); i++){
	edge e = v[i];
	if(c[e.from] != INF && c[e.to] > c[e.from] + e.cost){
	  c[e.to] = c[e.from] + e.cost;
	  update = true;
	}
      }
      if(!update) break;
    }
    cout << c[to] << endl;
  }
  else{
    t[f] = 0;
    while(true){
      bool update = false;
      for(int i=0; i<v.size(); i++){
	edge e = v[i];
	if(t[e.from] != INF && t[e.to] > t[e.from] + e.time){
	  t[e.to] = t[e.from] + e.time;
	  update = true;
	}
      }
      if(!update) break;
    }
    cout << t[to] << endl;
  }
}
int main(){
  

  while(cin >> n >> m && (n|m)){
    v.clear();
    for(int i=0; i<n; i++){
      cin >> ed.from >> ed.to >> ed.cost >> ed.time;
      v.push_back(ed);
      int dummy = ed.to;
      ed.to = ed.from;
      ed.from = dummy;
      v.push_back(ed);
    }
    
    cin >> k;
    for(int i=0; i<k; i++){
      cin >> p >> q >> r;
      shortest_path(p,q,r);
    }
  }
  return 0;
}
