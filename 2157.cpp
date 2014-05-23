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
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

string now,unlock;
int n,ans;

string createDial(string str, int start, int end){
//   cout << start << " " << end << endl;;
   int cnt = 0;
   while(1){
      if(str[start] == unlock[start])break;
      if(str[start] == '9') str[start] = '0';
      else str[start]++;
      cnt++;
   }

   for(int i=start+1; i<=end; i++){
      int a = str[i]-'0';
      if(a+cnt > 9) a = (a + cnt) - 10 ;
      else a += cnt;
      str[i] = a + '0';
   }
   return str;
}


int f(string str, int a, int cnt, int &ans){
//   cout << str << endl;
   if(a == n) return cnt;
   if(ans <= cnt) return ans;
   if(str[a] == unlock[a]) return f(str,a+1,cnt,ans);
   for(int i=a; i<n; i++){
      ans = min(ans,f(createDial(str,a,i),a+1,cnt+1,ans));
   }
   return ans;
}
int main(){
   while(cin >> n && n){
      cin >> now >> unlock;
      ans = 1<<29;
      cout << f(now,0,0,ans) << endl;
   }
   
  return 0;
}
