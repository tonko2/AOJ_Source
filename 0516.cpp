#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m,a,ans,sum;
  vector<int>v;
  while(cin >> n >> m && (n || m)){
    sum = 0;
    for(int i=0; i<n; i++){
      cin >> a;
      v.push_back(a);
    }

    for(int i=0; i<m; i++)  sum += v[i];
    ans = sum;
    for(int i=0; m<v.size(); i++,m++){
      sum += v[m] - v[i];
      ans = max(ans,sum);
    }

    cout << ans << endl;
  }
  return 0;
}
