#include <iostream>
using namespace std;

const int MAX = 20;
int d[MAX][MAX];
int V,E;

void warshall_floyd(){
  for(int k=0; k<V; k++)
    for(int i=0; i<V; i++)
      for(int j=0; j<V; j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}

int main(){
  char comma;
  fill(d[0],d[MAX],1000000);
  cin >> V >> E;
  int s1,s2,cost1,cost2;
  for(int i=0; i<E; i++){
    cin >> s1 >> comma >> s2 >> comma >> cost1 >> comma >> cost2;
    d[s1-1][s2-1] = cost1;
    d[s2-1][s1-1] = cost2;
  }
  warshall_floyd();
  int from,to,reward,value;
  cin >> from >> comma >> to >> comma >> reward >> comma >> value;
  int ans = reward - value;

  ans = ans - (d[from-1][to-1] + d[to-1][from-1]);

  cout << ans << endl;
  return 0;
}
