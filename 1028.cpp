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
const int coin[] = {1,5,10,50,100,500};
int main(){
  int total,y[6];
  while(cin >> total >> y[1] >> y[2] >> y[3] >> 
	y[4] >> y[5] >> y[6],(total|y[1]|y[2]|y[3]|y[4]|y[5]|y[6])){
    int ans = 0;
    for(int i=5; i>=0; i--){
      if(y[i+1]){
	ans += total / coin[i];
	y[i+1] -= total / coin[i];
	total %= coin[i];
      }
    }
    cout << ans << endl;
  } 
  return 0;
}
