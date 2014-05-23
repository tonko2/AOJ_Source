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

const int MAX = 10001;
int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      pair<int,int>p[MAX];
      int cnt = 0;
      ll ans = 0;
      for(int i=0; i<n; i++){
         cin >> p[i].second >> p[i].first;
         ans += p[i].second * p[i].first;
      }
      sort(p,p+n);
      reverse(p,p+n);
     
      int pos = -1;
      ll sum = 0;
      bool flag = false;
      for(int i=0; i<n; i++){
         if(m-p[i].second >= 0) sum += p[i].first * p[i].second,m-=p[i].second;
         else{
            pos = i;
            flag = true;
            break;
         }
      }
      if(flag) sum += p[pos].first * m;
      ans -= sum;
      cout << ans << endl;
   }
  return 0;
}
