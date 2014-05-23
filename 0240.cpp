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
   int n,y,b,t;
   double r;
   pair<double,int>p[101];
   while(cin >> n && n){
      cin >> y;
      for(int i=0; i<n; i++){
         cin >> b >> r >> t;
         if(t == 1){
            double tmp = 1 + (y * (r / 100));
            p[i] = make_pair(tmp,b);
         } else {
            double tmp = 1 + (r / 100);
            p[i] = make_pair(pow(tmp,y),b);
         }
      }
      sort(p,p+n);
      cout << p[n-1].second << endl;
   }
  return 0;
}
