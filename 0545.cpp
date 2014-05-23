#include <iostream>
#include <map>

using namespace std;

const int MAX_M = 10000;
int n,m;
map<int,int>M;
pair<int,int>p[MAX_M];

void solve(){
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      if(p[i].first == 1){
	M[p[i].second] = 1;
	if(p[i].second == p[j].first && p[j].second != 1)
	  M[p[j].second] = 1;
	else if(p[i].second == p[j].second && p[j].first != 1)
	  M[p[j].first] = 1;
      }
      else if(p[i].second == 1){
	M[p[i].first] = 1;
	if(p[i].first == p[j].first && p[j].second != 1)
	  M[p[j].second] = 1;
	else if(p[i].first == p[j].second && p[j].first != 1)
	  M[p[j].first] = 1;
      }
    }
  }
  map<int,int>::iterator it = M.begin();

  int res = 0;

  while(it != M.end()){
    res += (*it).second;
    it++;
  }

  cout << res << endl;
}

int main(){
  while(cin >> n >> m && (n || m)){
    M.clear();
    for(int i=1; i<=n; i++)
      M[i] = 0;
    for(int i=0; i<m; i++)
      cin >> p[i].first >> p[i].second;
    solve();
  }
  return 0;
}
