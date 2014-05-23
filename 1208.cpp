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
#include <cctype>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int p,n;
   while(cin >> p >> n,p|n){

      double ans = 1<<29;
      double ans2 = 1<<29;
      int a,b,c,d;
      
      for(int i=1; i<=n; i++){
         double T = sqrt((double)p) * i;
         int x = ceil(T);
         int x2 = floor(T);
         double t = (double)x / i;
         double t2 = (double)x2 / i;
         double tmp = abs(sqrt((double)p)-t);
         double tmp2 = abs(sqrt((double)p)-t2);
         if(tmp < ans && x <= n){
            ans = tmp;
            a = x;
            b = i;
         }

         if(tmp2 < ans2 && x2 <= n){
            ans2 = tmp2;
            c = x2;
            d = i;
         }
      }

      cout << a << "/" << b << " " << c << "/" << d << endl;
   }
 
  return 0;
}
