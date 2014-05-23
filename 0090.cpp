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
typedef pair<int,int> P;
const double PI = acos(-1);

#define REP(i,b,n) for(int i=b; i<n; i++)
#define rep(i,n) REP(i,0,n)

bool dis(pair<double,double>p1, pair<double,double>p2){
   double value = (double)sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2)) + (1e-8);
   if(value <= 2.0)return true;
   else return false;
}

int main(){
   int n;
   char comma;
   while(cin >> n && n){
      pair<double,double>p[100];
      pair<double,double>p2;
      for(int i=0; i<n; i++){
         cin >> p2.first >> comma >> p2.second;
         p[i] = p2;
      }

      int ans = 0;
      for(int i=0; i<n; i++){
         int cnt = 1;
         for(int j=0; j<n; j++){
            if(i == j)continue;
            if(dis(p[i],p[j])) cnt++;
         }
         ans = max(ans,cnt);
      }
      cout << ans << endl;
   }
  return 0;
}
