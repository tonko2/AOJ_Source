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
 
bool expression(State &begin);
bool f(State &begin);
bool factor(State &begin);
bool alpha(State &begin);
 
map<char,int>m;
int mask;
 
bool alpha(State &begin){
   bool res = false;
   if(*begin >= 'a' && *begin <= 'k'){
      res = (mask >> (m[*begin])) & 1;
      begin++;
   } else if(*begin == 'T'){
      res = true;
      begin++;
   } else if(*begin == 'F'){
      res = false;
      begin++;
   }
   return res;
}
 
bool factor(State &begin){
   bool res = false;
   if(*begin == '('){
      begin++;
      res = expression(begin);
      begin++;
   } else res = alpha(begin);
   return res;
}
bool f(State &begin){
   bool res = factor(begin);
   while(1){
      if(*begin == '-'){
         begin++;
         res = !f(begin);
      } else break;
   }
   return res;
}
 
bool expression(State &begin){
   bool res = f(begin);
   while(1){
      if(*begin == '+'){
         begin++;
         res |= f(begin);
      } else if(*begin == '*'){
         begin++;
         res &= f(begin);
      } else if(*begin == '>'){
         begin++;
         bool tmp = f(begin);
         if(res && !tmp) res = false;
         else res = true;
      } else break;
   }
   return res;
}
int main(){
   string s;
   while(cin >> s){
      if(s[0] == '#')break;
      int pos = 0;
      int cnt = 0;
      m.clear();
      string tmp = s;
      s = "";
 
      for(int i=0; i<tmp.size(); i++){
         if(tmp[i] == '-' && tmp[i+1] == '>') s += '>',i++;
         else s += tmp[i];
      }
 
      for(int i=0; i<s.size(); i++){
         if(s[i] == '=') pos = i;
         if(s[i] >= 'a' && s[i] <= 'k'){
            if(m.count(s[i]) == 0) m[s[i]] = cnt++;
         }
 
      }
       
      string left = s.substr(0,pos);
      string right = s.substr(pos+1,s.size());
      bool flag = true;
         for(int i=0; i<(1<<cnt); i++){
            mask = i;
            State L = left.begin();
            State R = right.begin();
            bool l = expression(L);
            bool r = expression(R);
//            cout << l << " " << r << endl;
            if(l != r){
               flag = false;
               break;
            }
         }
         if(flag) cout << "YES" << endl;
         else cout << "NO" << endl;
   }
   return 0;
}
