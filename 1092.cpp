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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int s,d,m;
   while(cin >> s >> d >> m){
      vector<vector<pair<int,int> > >v(s);
      for(int i=0; i<s; i++){
         int in;
         cin >> in;
         for(int j=0; j<in; j++){
            pair<int,int>p;
            cin >> p.first >> p.second;
            v[i].push_back(p);
         }
      }

      vector<int>V;
      V.resize(d);

      for(int i=0; i<d; i++) cin >> V[i];

      int dp[110][310];
      memset(dp,0,sizeof(dp));

      for(int i=0; i<V.size(); i++){
         int index = V[i];
         for(int j=0; j<v[index].size(); j++){
            int price = v[index][j].first, weight = v[index][j].second;
            for(int k=m; k>=0; k--){
               if(k-weight >= 0)
                  dp[i][k] = max(dp[i][k],dp[i][k-weight]+price);
            }
         }

         for(int j=0; j<=m; j++)
            dp[i+1][j] = dp[i][j];
      }

      int ansW = 0,ansP = 0;
      for(int i=0; i<=m; i++){
         if(ansP < dp[d][i]){
            ansP = dp[d][i];
            ansW = i;
         }
      }
      cout << ansP << " " << ansW << endl;
   }
  return 0;
}
