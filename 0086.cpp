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

int main(){
  int a,b,c,d,cnt[101];
  while(cin >> a >> b){
    fill(cnt,cnt+101,0);
    cnt[a-1]++;
    cnt[b-1]++;
    while(cin >> c >> d,(c|d)){
      cnt[c-1]++;
      cnt[d-1]++;
    }
    int odd = 0;
    for(int i=2; i<101; i++){
      cout << "cnt[" << i << "] = " << cnt[i] << endl;
      if(cnt[i] % 2 != 0 && cnt[i] > 0)odd++;
    }
    if(odd == 2) cout << "OK" << endl;
    else cout << "NG" << endl;
  }
  return 0;
}
