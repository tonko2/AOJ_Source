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

const int MAX = 20010;
int main(){
  int n,m,data[MAX],ans;
  while(cin >> n >> m,(n|m)){
    ans = 0;
    data[0] = 0;
    for(int i=1; i<=n+m; i++) cin >> data[i];
    sort(data,data+n+m+1);
    for(int i=0; i<n+m; i++)
      ans = max(ans,data[i+1]-data[i]);
    cout << ans << endl;
  }
  return 0;
}
