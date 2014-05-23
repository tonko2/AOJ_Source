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

string A(string s){
   string tmp = s;
   reverse(tmp.begin(),tmp.end());
   return tmp;
}

string C(string s){
   string tmp = s.substr(1,s.size()-1);
   tmp += s[0];
   return tmp;
}

string P(string s){
   string tmp = s;
   for(int i=0; i<tmp.size(); i++){
      if(tmp[i] >= '0' && tmp[i] <= '9'){
         if(tmp[i] == '0') tmp[i] = '9';
         else tmp[i]--;
      }
   }
   return tmp;
}

string M(string s){
   string tmp = s;
   for(int i=0; i<tmp.size(); i++){
      if(tmp[i] >= '0' && tmp[i] <= '9'){
         if(tmp[i] == '9') tmp[i] = '0';
         else tmp[i]++;
      }
   }
   return tmp;
}

string J(string s){
   string tmp;
   tmp += s[s.size()-1];
   tmp += s.substr(0,s.size()-1);
   return tmp;
}

string E(string s){
   string left,right;
   if(s.size() % 2 == 0){
      left = s.substr(0,s.size()/2);
      right = s.substr(s.size()/2,s.size()-s.size()/2);
      return right+left;
   } else {
      left = s.substr(0,s.size()/2);
      right = s.substr(s.size()/2+1,s.size()/2);
      return right + s[s.size()/2] + left;
   }
}

int main(){
   int n;
   cin >> n;
   for(int t=0; t<n; t++){
      string s,s2;
      cin >> s >> s2;
      for(int i=s.size()-1; i>=0; i--){
         if(s[i] == 'A') s2 = A(s2);
         else if(s[i] == 'J') s2 = J(s2);
         else if(s[i] == 'M') s2 = M(s2);
         else if(s[i] == 'P') s2 = P(s2);
         else if(s[i] == 'C') s2 = C(s2);
         else if(s[i] == 'E') s2 = E(s2);
      }
      cout << s2 << endl;
   }
  return 0;
}
