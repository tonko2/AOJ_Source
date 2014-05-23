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

int d[110];
int cost[110][110];
bool used[110];
int cnt;
void dijkstra(int s){
   for(int i=0; i<110; i++){
      used[i] = false;
      d[i] = INF;
   }

   d[s] = 0;

   
}
int main(){
   int n;
   cin >> n;
   cin.ignore();
   map<string,int>m;
   vector<pair<string,string> >v;
   cnt = 1;
   fill(cost[0],cost[110],INF);
   for(int i=0; i<n; i++){
      string s,s2;
      cin >> s;
      if(s == "goto"){
         cin >> s2;
         s2 = s2.substr(0,s2.size()-1);
      } else {
         s = s.substr(0,s.size()-1);
         m[s] = cnt++;
      }
      
      v.push_back(mp(s,s2));
   }
   int now = 0;
   if(v[0].second == ""){
      int a = m[v[0].first];
      cost[now][a] = 1;
   }
   for(int i=0; i<v.size(); i++){
      string s = v[i].first, s2 = v[i].second;
      if(s2 == "") now = m[s];
      else {
         int to = m[s2];
         cost[now][to] = 1;
      }
   }

   for(int i=0; i<cnt; i++){
      for(int j=0; j<cnt; j++){
         cout << cost[i][j] << " ";
      }
      cout << endl;
   }
  return 0;
}
