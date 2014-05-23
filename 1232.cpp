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
const int MAX = 100000;
const int MAX_N = 8000;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

struct State{
   ll value;
   int p,q;
   State(ll v, int _p, int _q){
      value = v;
      p = _p;
      q = _q;
   }
};

vector<int>v;
vector<State>vv;
bool p[MAX];

bool compare(State a, State b){
   return a.p*a.q > b.p * b.q;  
}
void init(){
   fill(p,p+MAX_N,true);
   p[0] = p[1] = false;
   for(int i=2; i*i<MAX_N; i++)
      for(int j=i*2; j<MAX_N; j+=i) p[j] = false;

   for(int i=2; i<MAX_N; i++){
      if(p[i]) v.push_back(i);
   }

   for(int i=0; i<v.size(); i++){
      for(int j=i; j<v.size(); j++){
         if(v[i]*v[j] >= MAX)break;
         ll tmp = v[i]*v[j];
         vv.push_back(State(tmp,v[i],v[j]));
      }
   }

   sort(vv.begin(),vv.end(),compare);
}
int main(){
   init();
   int m,a,b;
   while(cin >> m >> a >> b,m|a|b){

      for(int i=0; i<vv.size(); i++){
         ll p = vv[i].p, q = vv[i].q;
         if(p * q <= m && (double)a/b <= (double)p/q && (double)p/q <= 1.0){
            cout << p << " " << q << endl;
            break;
         }
      }
   }
  return 0;
}
