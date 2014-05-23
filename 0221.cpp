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
using namespace std;

typedef long long int lli;
typedef pair<int,int> P;
const double PI = acos(-1);

#define REP(i,b,n) for(int i=b; i<n; i++)
#define rep(i,n) REP(i,0,n)

int main(){
   int n,m;
   string s;
   char c[100];
   while(cin >> n >> m,(n|m)){
      vector<int>v;
      for(int i=1; i<=n; i++)v.push_back(i);
      int cnt = 0,w = -1;
      for(int i=1; i<=m; i++){
         cin >> s;
         if(w != -1) continue;
         sprintf(c,"%d",i);
         if(i % 3 == 0 && i % 5 == 0){
            if(s == "FizzBuzz")cnt++;
            else v.erase(v.begin()+cnt);
         } else if(i % 3 == 0){
            if(s == "Fizz") cnt++;
            else v.erase(v.begin()+cnt);
         } else if(i % 5 == 0){
            if(s == "Buzz") cnt++;
            else v.erase(v.begin()+cnt);
         } else{
            if(s == c) cnt++;
            else v.erase(v.begin()+cnt);
         }
         cnt %= v.size();
         if(v.size() == 1) w = v[0];
      }
      if(w != -1) cout << w << endl;
      else{
         for(int i=0; i<v.size(); i++){
            if(i == 0) cout << v[i];
            else cout << " " << v[i];
      }
         cout << endl;
      }
   }
   return 0;
}
