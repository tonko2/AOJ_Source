#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <complex>
using namespace std;

#define X real()
#define Y imag()
typedef long long int lli;
typedef pair<int,int> P;
const double PI = acos(-1);

#define REP(i,b,n) for(int i=b; i<n; i++)
#define rep(i,n) REP(i,0,n)

int main(){
   int n;
   double edge[100],x[100],y[100];
   int cnt = 0;
   while(cin >> n && n){

      for(int i=0; i<n; i++){
         cin >> x[i] >> y[i];
      }
      cin.ignore();
      double ans = 0;
      for(int i=0; i<n; i++){
         int j = (i+1)%n;
         ans += (x[j]*y[i]) - (x[i]*y[j]);
      }
      cout << fixed << setprecision(1);
      cout << ++cnt << " " << abs(ans/2.0) << endl;
   }
   return 0;
}
