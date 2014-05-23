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
const char ans[4][20] = {"perfect number","deficient number","abundant number"};
int main(){
  lli n,i;
  while(cin >> n && n){
    int sum = 0;
    for(int i=1; i*i<=n; i++){
      if(n%i == 0){
	sum += i + n/i;
	if(i == n/i) sum -= n/i;
      }
    }
    sum -= n;
    if(sum == n) cout << ans[0] << endl;
    else if(sum < n) cout << ans[1] << endl;
    else cout << ans[2] << endl;
  }
  return 0;
}
