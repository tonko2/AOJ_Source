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
vector<int> alpha(State &begin);
vector<int> factor(State &begin);
vector<int> expression(State &begin);
vector<int> f(State &begin);

string s;
map<char,int>m;
vector<int>v[6];
set<int>u;
vector<int>U;
int cnt;

void func(vector<int> res){
   sort(res.begin(),res.end());
   res.erase(unique(res.begin(),res.end()),res.end());
}

void init(){
   U.clear();
   u.clear();
   m.clear();
   cnt = 0;
   for(int i=0; i<6; i++) v[i].clear();
}

vector<int> alpha(State &begin){
   vector<int>res;
   if(*begin >= 'A' && *begin <= 'E'){
      for(int i=0; i<v[m[*begin]].size(); i++){
         res.push_back(v[m[*begin]][i]);
      }
      begin++;
   }
   func(res);
   return res;
}

vector<int> factor(State &begin){
   vector<int>res;
   if(*begin == '('){
      begin++;
      res = expression(begin);
      begin++;
   } else res = alpha(begin);
   func(res);
   return res;
}

vector<int> f(State &begin){
   vector<int>res = factor(begin);
   while(1){
      if(*begin == 'c'){
         begin++;
         vector<int> tmp = f(begin);
         vector<int>tmp2;
         for(int i=0; i<U.size(); i++){
            int t = U[i];
            bool flag = true;
            for(int j=0; j<tmp.size(); j++){
               if(U[i] == tmp[j]) flag = false;
            }
            if(flag) tmp2.push_back(t);
         }
         res = tmp2;
      } else break;
   }
   func(res);
   return res;
}
vector<int> expression(State &begin){
   vector<int>res = f(begin);
   while(1){
      if(*begin == 'u'){
         begin++;
         vector<int>tmp = f(begin);
         for(int i=0; i<tmp.size(); i++) res.push_back(tmp[i]);
         sort(res.begin(),res.end());
         res.erase(unique(res.begin(),res.end()),res.end());
      } else if(*begin == 'i'){
         begin++;
         vector<int>tmp = f(begin);
         vector<int>tmp2;
         for(int i=0; i<tmp.size(); i++){
            for(int j=0; j<res.size(); j++){
               if(tmp[i] == res[j]) tmp2.push_back(tmp[i]);
            }
         }
         res = tmp2;
      } else if(*begin == 'd'){
         begin++;
         vector<int>tmp = f(begin);
         vector<int>tmp2;
         for(int i=0; i<res.size(); i++){
            bool flag = true;
            for(int j=0; j<tmp.size(); j++){
               if(res[i] == tmp[j]) flag = false;
            }
            if(flag) tmp2.push_back(res[i]);
         }
         res = tmp2;
      } else if(*begin == 's'){
         begin++;
         vector<int>tmp = f(begin);
         vector<int>tmp2;
         for(int i=0; i<res.size(); i++){
            bool flag = true;
            for(int j=0; j<tmp.size(); j++){
               if(res[i] == tmp[j]) flag = false;
            }
            if(flag) tmp2.push_back(res[i]);
         }
         
         for(int i=0; i<tmp.size(); i++){
            bool flag = true;
            for(int j=0; j<res.size(); j++){
               if(tmp[i] == res[j]) flag = false;
            }
            if(flag) tmp2.push_back(tmp[i]);
         }
         res = tmp2;
      } else break;
   }
   func(res);
   return res;
}

int main(){
   char c;
   int num;
   cnt = 0;
   while(cin >> c >> num){

      if(m.count(c) == 0){
         m[c] = cnt++;
         for(int i=0; i<num; i++){
            int in;
            cin >> in;
            v[m[c]].push_back(in);
            u.insert(in);
         }
      }
    
      if(!(c == 'R' && num == 0))continue;

      set<int>::iterator it = u.begin();
      while(it != u.end()){
         U.push_back(*it);
         it++;
      }
      
      cin >> s;
      State str = s.begin();
      vector<int> ans = expression(str);

      if(ans.size() == 0) cout << "NULL" << endl;
      else {
         for(int i=0; i<ans.size(); i++){
            if(i == 0) cout << ans[i];
            else cout << " " << ans[i];
         }
         cout << endl;
      }
      init();
   }
   return 0;
}
