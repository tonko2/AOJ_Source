#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <cctype>
#include <math.h>

#define mp make_pair

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int n;
   while(cin >> n && n){
      int dis[30010];
      int Max = 0;
      for(int i=1; i<=n; i++){
         cin >> dis[i];
         Max = max(Max,dis[i]);
      }
      
      double b,r,v,e,f,time;
      double t[30010];
      double ans[30010];
      fill(ans,ans+30010,INF);
      ans[0] = 0;
      memset(t,0,sizeof(t));
      
      cin >> b;
      cin >> r >> v >> e >> f;

      double total = 0;
      t[0] = total;
      for(int i=0; i<=Max; i++){
         double x = i;
         if(x >= r){
            time = 1.0 / (v - e * (x - r));
         } else {
            time = 1.0 / (v - f * (r - x));
         }
         total += time;
         t[i+1] = total;
      }

      for(int i=0; i<n; i++){
         for(int j=i+1; j<=n; j++){
            time = t[dis[j]-dis[i]];
            if(i != 0) time += b;
            ans[dis[j]] = min(ans[dis[j]],ans[dis[i]]+time);

         }
      }
      
      printf("%.5f\n",ans[Max]);
   }
   return 0;
}
