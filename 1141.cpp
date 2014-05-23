#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
using namespace std;

typedef long long int lli;
bool prime[10000000];
int main(){
  fill(prime,prime+10000000,1);
  prime[0] = prime[1] = 0;
  for(int i=2; i<sqrt(10000000); i++){
    for(int j=2*i; j<=10000000; j+=i){
      if(prime[j]) prime[j] = 0;
    }
  }

  lli a,d,n,cnt=0,ans;
  while(cin >> a >> d >> n,(a|d|n)){
    cnt = 0;
    for(lli i=a; ; i+= d){

      if(prime[i]) cnt++;
      
      if(cnt == n){
	//	cout << "i = " << i << endl;
	ans = i;
	break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
