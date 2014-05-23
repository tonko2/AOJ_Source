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

string toStr(int a){
   ostringstream oss;
   oss << a;
   return oss.str();
}

bool isPalin(int a){
   string s = toStr(a);
   string tmp = s;
   reverse(tmp.begin(),tmp.end());
   return tmp == s;
}
int main(){
   int n;
   vector<int>v;
   for(int i=0; i<=10000; i++){
      if(isPalin(i)) v.push_back(i);
   }
   while(cin >> n){
      int ans = 0;
      int a = 1<<29;
      for(int i=0; i<v.size(); i++){
         if(abs(v[i]-n) < a){
            a = abs(v[i]-n);
            ans = v[i];
         }
      }
      cout << ans << endl;
   }
  return 0;
}
