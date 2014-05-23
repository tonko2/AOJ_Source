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

const int MAX = 65001;
int main(){
   int n;
   int array[MAX],p[MAX];
   while(cin >> n && n){
      ll sum = 0;
      for(int i=0; i<n; i++){
         cin >> array[i];
         sum += array[i];
      }
      
      for(int i=0; i<n-1; i++) cin >> p[i];
      
      sort(p,p+n-1);
      reverse(p,p+n-1);
      ll ans = sum * n;
      ll pipe = 0;
      for(int i=1; i<n; i++){
         pipe += p[i-1];
         ans = max(ans,(ll)(sum + pipe) * (n-i));
      }
      
      cout << ans << endl;
   }
   
  return 0;
}
