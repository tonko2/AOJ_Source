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
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int n,m;
   cin >> n >> m;
   int ans = m,now = m;
   pair<int,int>p[10001];
   for(int i=0; i<n; i++){
      cin >> p[i].first >> p[i].second;
   }
   for(int i=0; i<n; i++){
      int a,b;
      a = p[i].first, b = p[i].second;
      if(a+now - b < 0){
         ans = 0;
         break;
      }
      now = a+now-b;
      ans = max(ans,now);
   }
   cout << ans << endl;
  return 0;
}
