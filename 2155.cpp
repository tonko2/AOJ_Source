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

const int MAX = 20001;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

class State{
public:
   int t,s,d;
   bool operator < (const State &s) const {
      return t < s.t;
   }
};
int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      State a[MAX];
      bool visit[MAX];
      fill(visit,visit+MAX,0);
      visit[0] = 1;
      for(int i=0; i<m; i++){
         cin >> a[i].t >> a[i].s >> a[i].d;
         a[i].s--,a[i].d--;
      }

      sort(a,a+m);

      for(int i=0; i<m; i++){
         int from,to;
         from = a[i].s;
         to = a[i].d;
         if(visit[to]) continue;
         visit[to] = visit[from];
      }

      int cnt = 0;
      for(int i=0; i<n; i++)
         if(visit[i])cnt++;
      cout << cnt << endl;
   }
  return 0;
}
