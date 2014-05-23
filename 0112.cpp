#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10000;
long long ans,ans2;
int main(){
  int n,a;
  vector<int>v;
  
  while(cin >> n && n){
    ans = 0,ans2 = 0,v.clear();
    for(int i=0; i<n; i++){
      cin >> a;
      v.push_back(a);
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0; i<v.size()-1; i++){
      ans2 += ans + v[i];
      ans += v[i];
    }
    cout << ans2 << endl;
  }
  return 0;
}
