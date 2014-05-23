#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n,a[10],k=1,b[10];
  vector<int>v;
  for(int i=0; i<10; i++){
    a[i] = k*1;
    k *= 2;
  }

  while(cin >> n){
    v.clear();
    for(int i=9; i>=0; i--){
      if(n - a[i] >= 0){
	v.push_back(a[i]);
	n -= a[i];
	//	cout << n << endl;
      }
    }
      sort(v.begin(),v.end());
     for(int i=0; i<v.size(); i++){
      if(i == v.size()-1)
	cout << v[i] << endl;
      else
      cout << v[i] << ' ';
      }
  }
  return 0;
}
