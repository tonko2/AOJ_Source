#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int,int> > s;
vector<pair<int,int> > v;
pair<int,int> p;

int main(){
  int n;
  
  while(cin >> n && n){
    s.clear();
    v.clear();
    int ans = 0;
    for(int i=0; i<n; i++){
      cin >> p.first >> p.second;
      s.insert(p);
      v.push_back(p);
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	int a = v[i].first - v[j].first;
	int b = v[i].second - v[j].second;
	if(s.find(pair<int,int>(v[i].first - b, v[i].second + a)) != s.end() &&
	   s.find(pair<int,int>(v[j].first - b, v[j].second + a)) !=s.end())
	  ans = max(ans,a*a + b*b);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
