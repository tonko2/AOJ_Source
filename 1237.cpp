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

int toInt(string s){
   stringstream ss(s);
   int a;
   ss >> a;
   return a;
}

int main(){
   int n;
   string s;
   while(cin >> n >> s){
      if(n == 0 && s == "0")break;
      map<pair<int,vector<string> >,int>m;
      map<int,int>m2;
      
      for(int i=0; i<(1<<s.size()-1); i++){
         int prev = 0, value = 0;
         vector<string>v;
         for(int j=0; j<s.size(); j++){
            if((1<<j) & i){
               if(j == s.size()-1)continue;
               v.push_back(s.substr(prev,j+1-prev));
               value += toInt(s.substr(prev,j+1-prev));
               prev = j+1;
            }
         }
         value += toInt(s.substr(prev,s.size()-prev));
         v.push_back(s.substr(prev,s.size()-prev));
         m[mp(value,v)]++;
         m2[value]++;
      }

      map<pair<int,vector<string> >,int >::iterator it = m.begin();
      if(it->first.first > n){
         cout << "error" << endl;
         continue;
      }

      int ans = 0;
      vector<string>ans2;
      while(it != m.end()){
         if(ans <= it->first.first && it->first.first <= n){
            ans = it->first.first;
            ans2 = it->first.second;
         }
         it++;
      }

      if(m2[ans] != 1){
         cout << "rejected" << endl;
         continue;
      }
      cout << ans << " ";
      for(int i=0; i<ans2.size(); i++){
         if(i == 0) cout << ans2[i];
         else cout << " " << ans2[i];
      }
      cout << endl;
   }
  return 0;
}
