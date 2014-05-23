#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool prime[MAX];
int main(){
  fill(prime,prime+MAX,1);
  prime[0] = prime[1] = 0;
  for(int i=2; i<sqrt(MAX); i++){
    for(int j=i*2; j<=MAX; j+=i){
      if(prime[j]) prime[j] = 0;
    }
  }
  
  int n;
  vector<int>v;
  for(int i=2; i<=MAX; i++){
    if(prime[i])
      v.push_back(i);
  }

  vector<int>::iterator it;
  while(cin >> n && n){
    int ans = 0;
    /*    for(int i=0; v[i]<n; i++){
      it = upper_bound(v.begin()+i,v.end(),n-v[i]);
      if(*it == n-v[i]){
	ans++;
      	cout << "a" << endl;
     }
     }*/

    for(int i=2; i<=n/2; i++){
      if(prime[i] && prime[n-i])
	ans++;
    }
    cout << ans << endl;  
  }
  return 0;
}
