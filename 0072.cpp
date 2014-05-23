#include <iostream>
using namespace std;

const int MAX = 1000;
const int INF = 100000;
int d[MAX][MAX],n;

void warshall_floyd(){
 
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}
int main(){
  int m,ans=INF,sum=0;
  char c;
  while(cin >> n && n){
    cin >> m;
    fill(d[0],d[MAX],INF);
    for(int i=0; i<m; i++){
      int s,t,cost;
      cin >> s >> c >> t >> c >> cost;
      d[s][t] = cost;
      d[t][s] = cost;
    }
    warshall_floyd();

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	if(i != j)
	sum += d[i][j];
      }
      ans = min(ans,sum);
      sum = 0;
    }

    cout << (ans/100) - (n-1) << endl;    

  }
  return 0;
}
