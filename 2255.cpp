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
typedef string::const_iterator State;
int expression(State begin);
int f(State begin);
int factor(State begin);
int number(State begin);
map<int,int>m;
string s;

int number(State begin){
   int res = 0;

   while(isdigit(*begin)){
      if(*begin >= '0' && *begin <= '9'){
         res *= 10;
         res += *begin-'0';
      } else break;
      begin++;
   }
   return res;
}

int factor(State begin){
   int res = 0;
   if(*begin == '('){
      begin++;
      res = expression(begin);
      begin++;
   } else res = number(begin);
   return res;
}

int f(State begin){
   int res = factor(begin);

   while(1){
      if(*begin == '*'){
         begin++;
         res *= factor(begin);
      } else if(*begin == '/'){
         begin++;
         res /= factor(begin);
      } else break;
   }
   return res;
}

int expression(State begin){
   int res = f(begin);

   while(1){
      if(*begin == '+'){
         begin++;
         res += f(begin);
      } else if(*begin == '-'){
         begin++;
         res -= f(begin);
      } else break;
   }
   return res;
}
int main(){
   while(cin >> s){
      if(s[0] == '#')break;
      State str = s.begin();
      m.clear();
      int ans = expression(str);
      cout << ans << endl;
   }
  return 0;
}
