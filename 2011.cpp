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

ll dp[32][32];
int main(){
   int n;
   while(cin >> n && n){
      memset(dp,0,sizeof(dp));
      for(int i=0; i<n; i++) dp[0][i] = 1LL<<i;
      vector<vector<int> >v;
      v.resize(32);
      for(int i=0; i<n; i++){
         int a;
         cin >> a;
         for(int j=0; j<a; j++){
            int b;
            cin >> b;
            v[b].push_back(i);
         }
      }

      int res = INF;

      for(int i=1; i<31; i++){
         for(int j=0; j<n; j++){
            dp[i][j] = dp[i-1][j];
            if(find(v[i].begin(),v[i].end(),j) != v[i].end())
               for(int k=0; k<v[i].size(); k++){
                  dp[i][j] |= dp[i-1][v[i][k]];
               }
            if(dp[i][j] == (1LL<<n)-1){
               res = i;
               goto end;
            }
            
         }
      }
      cout << -1 << endl;
      continue;      
     end:
      cout << res << endl;

   }
  return 0;
}
