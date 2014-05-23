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
const int INF = 1<<29;
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

const int MAX = 100001;
P par[MAX];
int C[MAX];             

             
void init(int n){
   for(int i=0; i<n; i++) par[i] = mp(-1,0);
}

P find(int x){
   if(par[x].first == -1) return mp(x,0);
   P r = find(par[x].first);
   return par[x] = mp(r.first,r.second + par[x].second);
}

bool same(int a, int b){
   return find(a).first == find(b).first;
}

void unite(int x, int y, int w){
   if(same(x,y)) return;
   P ra = find(x);
   P rb = find(y);
   par[ra.first] = mp(rb.first,w-ra.second+rb.second);

}
int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      init(n+1);
      memset(C,0,sizeof(C));
      while(m--){
         char c;
         int a,b;
         cin >> c >> a >> b;
         if(c == '!'){
            int w;
            cin >> w;
            unite(a,b,w);
         } else {
            if(same(a,b)){
               P ra = find(a);
               P rb = find(b);
               cout << ra.second - rb.second << endl;
            } else {
               cout << "UNKNOWN" << endl;
            }
         }
      }
   }
  return 0;
}
