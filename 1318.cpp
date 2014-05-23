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
const int MAX = 3000;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int cost[MAX][MAX];

int main(){
   int n,m,c;
   while(cin >> n >> m >> c,n|m|c){
      fill(cost[0],cost[MAX],INF);
      map<string,int>m;
      int cnt = 0;
      string start,end;
      cin >> start >> end;

      for(int i=0; i<n; i++){
         string s,e;
         int c,from,to;
         cin >> s >> e >> c;
         if(m[s]) from = m[s];
         else{
            m[s] = cnt;
            from = cnt;
            cnt++;
         }
         if(m[e]) to = m[e];
         else{
            m[e] = cnt;
            to = cnt;
            cnt++;
         }

         cost[from][to] = c;
         cost[to][from] = c;
      }
      
   }
  return 0;
}
