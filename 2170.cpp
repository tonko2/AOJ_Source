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


bool marked[100001];
class Union_Find{
public:
   vector<int>par,rank;
   Union_Find(){}

   void init(int n){
      par.resize(n);
      rank.resize(n);
      for(int i=0; i<n; i++){
         par[i] = i;
         rank[i] = 0;
      }
   }

   int find(int x){
      if(abs(par[x]) == x) return x;
      return find(par[x]);
   }

   int find2(int x){
      if(marked[x]) return x;
      return find2(par[x]);
   }
   
   bool same(int x, int y){
      return abs(find(x)) == abs(find(y));
   }

  
   void unite(int x, int y){
      int xx = find(x);
      int yy = find(y);
//      if(xx == yy)return;

      if(xx == 1){
         par[y] = x;
      } else {
         par[x] = y;
      }
      
   } 
};

int main(){
   int N,Q;
   while(cin >> N >> Q,N|Q){
      memset(marked,0,sizeof(marked));
      Union_Find uf;
      uf.init(N+1);
      int in;
      for(int i=2; i<=N; i++){
         cin >> in;
         uf.unite(i,in);
      }

      char c;
      int node;
      ll ans = 0;
      marked[1] = true;
      for(int i=0; i<Q; i++){
         cin >> c >> node;
         if(c == 'Q'){
            int cnt = uf.find2(node);
            ans += cnt;
//            cout << "cnt = " << cnt << endl;
         } else marked[node] = true;

      }
         cout << ans << endl;
   }

   
  return 0;
}
