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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;


class Color{
public:
   double l,a,b;
   bool operator < (const Color &s) const {
      return true;
   }
};

int main(){
   int n,m;
   while(cin >> n >> m){
      Color c[21];
      for(int i=0; i<n; i++){
         cin >> c[i].l >> c[i].a >> c[i].b;
      }

      double ans = 0;
      if(m == 1){
         printf("%.6f\n",ans);
         continue;
      }

      cout << fixed << setprecision(8);
      
      for(int S=0; S<(1<<n); S++){
         vector<Color>v;
         for(int i=0; i<n; i++){
            if((S >> i) & 1) v.push_back(c[i]);
         }
         if(v.size() != m)continue;
         double tmp = 0;


         
         for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
               double L = fabs(v[i].l - v[j].l);
               double A = fabs(v[i].a - v[j].a);
               double B = fabs(v[i].b - v[j].b);
               tmp += L*L + A*A + B*B;
            }
         }
         ans = max(ans,tmp);
         
      }

      printf("%.6f\n",ans);
   }
  return 0;
}
