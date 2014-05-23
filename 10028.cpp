#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,a;
  vector<int>v;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(),v.end());

  for(int i=0; i<n; i++){
    if(i != 0){
      cout << ' ' << v[i];
    }
    else
      cout << v[i];
  }
  cout << endl;
  return 0;
}
