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
   string str;
   while(cin >> n,n){
      cin >> m >> str;
      string s = "IOI";
      for(int i=1; i<n; i++){
         s += "OI";
      }

      int ans = 0;
      for(int i=0; i<m; i++){
         if(str.substr(i,2*n+1) == s) ans++;
      }
      cout << ans << endl;
   }
  return 0;
}
