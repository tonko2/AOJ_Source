#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int n,a,flag;
  map<int,long long>m;
  vector<int>v;
  long long b,c;
  while(cin >> n,n){
    flag = 0;
    m.clear();
    v.clear();

    for(int i=0; i<n; i++){
      cin >> a >> b >> c;
      if(!m[a])
	v.push_back(a);
      m[a] += b * c;    
    };

    for(int i=0; i<v.size(); i++){
      if(m[v[i]] >= 1000000){
	cout << v[i] << endl;
	flag = 1;
      }
    }
    if(flag == 0)
      cout << "NA" << endl;
  }
  return 0;
}
