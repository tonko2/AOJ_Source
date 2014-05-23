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

string s;

//turn 0 is left, turn 1 is right
int dfs(int n, bool turn, int left, int right){
   if(n == s.size()) return 0;
   int next = (s[n]-'1') % 3;
   if(!turn){
      if(right >= next) return dfs(n+1,!turn,next,right);
      else return dfs(n+1,turn,left,next)+1;
   } else {
      if(left <= next) return dfs(n+1,!turn,left,next);
      else return dfs(n+1,turn,next,right)+1;
   }
}
int main(){
   while(cin >> s){
      if(s == "#")break;
      if(s.size() == 1){
         cout << 0 << endl;
         continue;
      }
      int left = (s[0]-'1')%3;
      int right = (s[0]-'1')%3;;
      cout << min(dfs(1,0,left,right),dfs(1,1,left,right)) << endl;
      
   }
  return 0;
}
