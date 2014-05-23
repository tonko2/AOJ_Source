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
      return par[x] = find(abs(par[x])) * (par[x]>0?1:-1);
   }

   bool same(int x, int y){
      return abs(find(x)) == abs(find(y));
   }


//xとyが違うグループに属すようにする
   void dif(int x, int y){
      if(same(x,y)) return;
      x = find(x);
      y = find(y);

      par[abs(x)] = (x>0)?(-y):y;
   }
  
   void unite(int x, int y){
      x = find(x);
      y = find(y);
      if(x == y)return;


      if(rank[x] < rank[y]){
         par[x] = y;
      } else {
         par[y] = x;
         if(rank[x] == rank[y]) rank[x]++;
      }
   } 
};

struct edge{
   int from,to;
   double cost;
   edge(){}
   edge(int from, int to, double cost):from(from),to(to),cost(cost){}
};

bool comp(const edge& e1, const edge& e2){
   return e1.cost > e2.cost;
}

const int MAX_N = 100001;
edge es[100000];
int V,E;
Union_Find uf;


double kruskal(){
   sort(es,es+E,comp);
   double res = 0;
   for(int i=0; i<E; i++){
      edge e = es[i];
      if(!uf.same(e.from, e.to)){
         uf.unite(e.from,e.to);
         res += e.cost;
      }
   }
   return res;
}

double dis(double x, double y){
   return sqrt(x*x+y*y);
}

int main(){

   while(cin >> V >> E){
      uf.init(V+1);
      pair<double,double>p[V];

      for(int i=0; i<V; i++){
         cin >> p[i].first >> p[i].second;
      }
      double total = 0;
      int from,to;
      for(int i=0; i<E; i++){
         cin >> es[i].from >> es[i].to;
         from = es[i].from, to = es[i].to;
         from--,to--;
         double d = dis(p[from].first-p[to].first,p[from].second-p[to].second);
         total += d;
         es[i].cost = d;
      }

      printf("%.3f\n",total - kruskal());
      
   }
  return 0;
}
