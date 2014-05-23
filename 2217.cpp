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

bool used[101][101];
vector<vector<pair<int,int> > >v;

int X,Y,ans;

void dfs(int x, int y){
 
   
   if(v[y][x].first == x && v[y][x].second == y){
      ans++;
      used[y][x] = true;
      used[v[y][x].second][v[y][x].first] = true;
      return;
   }
   
  if(used[y][x]){
      return;
   }
   
   dfs(v[y][x].first, v[y][x].second);
}

int main(){
   int n;
   while(cin >> n && n){
      v.resize(101,vector<pair<int,int> >(101));

      for(int i=0; i<101; i++) v[i].clear();

      for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            cin >> v[i][j].first >> v[i][j].second;
         }
      }

      memset(used,0,sizeof(used));

      ans = 0;
      for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            if(used[i][j])continue;
//            used[i][j] = true;
//            ans++;
//            X = j, Y = i;
//            int x = v[i][j].first, y = v[i][j].second;
//            cout << "x = " << x << " y = " << y << endl;
            dfs(i,j);
         }
      }
      cout << ans << endl;
   }
   return 0;
}
