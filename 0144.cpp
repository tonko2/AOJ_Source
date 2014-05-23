#include <iostream>
#include <vector>
using namespace std;

const int MAX  = 100;
const int INF = 1000000;
int d[MAX],n,r,k,t,p;

struct edge{
  int from,to,cost;
};

vector<edge>es;

void bellman_ford(int s){
  for(int i=0; i<n; i++) d[i] = INF;

  d[s] = 0;

  while(1){
    bool update = false;
    for(int i=0; i<es.size(); i++){
      if(d[es[i].from] != INF && d[es[i].to] > d[es[i].from] + es[i].cost){
	d[es[i].to] = d[es[i].from] + es[i].cost;
	update = true;
      }
    }
    if(!update) break;
  }
}

int main(){
  while(cin >> n && n){
    es.clear();
    for(int i=0; i<n; i++){
      cin >> r >> k;
      for(int j=0; j<k; j++){
	edge e;
	cin >> t;
	e.from = r-1,e.to = t-1,e.cost = 1;
	es.push_back(e);
      }
    }
    cin >> p;
    
    for(int i=0; i<p; i++){
    int s,t,cost;
    cin >> s >> t >> cost;
    bellman_ford(s-1);
    
    if(d[t-1] < cost)
      cout << d[t-1] + 1 << endl;
    else if(d[t-1] >= cost || d[t-1] == INF)
      cout << "NA" << endl;   
    }
  }
  return 0;
}
