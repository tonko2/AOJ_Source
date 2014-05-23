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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

vector<int>v;
vector<int>v2;
int n,m,sum,ans,cnt;
int a[10];

int getCost(int i, int d){
   if(i % 2 == 0) d *= 2;
   if(d >= 10) d = d/10 + d%10;
   return d;
}
void dfs(int c, int s){
   if(c == v.size()){
      if(s % 10 == 0) ans++;
      return;
   }
   
   for(int i=0; i<m; i++){
      dfs(c+1,s+getCost(v[c],a[i]));
   }
}
int main(){

   while(cin >> n){
      v.clear();
      ans = sum = 0;
      string s;
      cin >> s;
      cin >> m;
      for(int i=0; i<m; i++) cin >> a[i];
      reverse(s.begin(),s.end());
      for(int i=1; i<=s.size(); i++){
         if(s[i-1] == '*') v.push_back(i);
         else sum += getCost(i,s[i-1]-'0');
      }
      dfs(0,sum);
      cout << ans << endl;      
   }
  return 0;
}
