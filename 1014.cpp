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
const int MAX = 201;
const int INF = 1<<29;
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}


int par[MAX];
int rank[MAX];
void init(int n){
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

struct edge {
   int u,v,cost;
   edge(int u, int v, int cost):u(u),v(v),cost(cost){}
};

bool comp(const edge& e1, const edge& e2){
   return e1.cost < e2.cost;
}

vector<edge>es;
int s,d;

int kruskal(){
   sort(es.begin(),es.end(),comp);
   init(s+d);

   int res = 0;

   for(int i=0; i<(int)es.size(); i++){
      edge e = es[i];
      if(!same(e.u,e.v)){
         bool flag = false, flag2 = false;
         for(int j=0; j<s; j++){
            if(same(j,e.u)) flag = true;
            if(same(j,e.v)) flag2 = true;
         }
         if(flag && flag2)continue;
         unite(e.u,e.v);
         res += e.cost;
//         cout << "res = " << e.cost << endl;
      }
   }
   return res;
}

int main(){

   while(cin >> s >> d ,s|d){
      int cost;
      es.clear();
      for(int i=0; i<s; i++){
         for(int j=0; j<d; j++){
            cin >> cost;
            if(cost == 0)continue;
            es.push_back(edge(i,s+j,cost));
//            es.push_back(edge(s+j,i,cost));
         }
      }

      for(int i=0; i<d-1; i++){
         for(int j=0; j<d-1-i; j++){
            cin >> cost;
            if(cost == 0)continue;
            es.push_back(edge(s+i,s+i+j+1,cost));
//            es.push_back(edge(s+i+j+1,s+i,cost));
         }
      }

      for(int i=0; i<es.size(); i++){
//         cout << es[i].u << " " << es[i].v << " " << es[i].cost << endl;
      }
      
      cout << kruskal() << endl;
      
   }

  return 0;
}
