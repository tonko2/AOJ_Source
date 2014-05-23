#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000;

int main(){
  int n,m;
  while(cin >> n >> m && (n || m)){
    vector<int>v;
    for(int i=1; i<=n; i++)
      v.push_back(i);

    vector<int>::iterator it = v.begin();

    while(v.size() != 1){
      for(int i=1; it = (it == v.end()) ? v.begin() : it ,i<m; i++)
	it++;
      it = v.erase(it);
    }
    cout << v[0] << endl;
  }
  return 0;
}
