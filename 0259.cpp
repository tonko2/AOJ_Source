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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

string toString(int n){
   ostringstream oss;
   oss << n;
   return oss.str();
}

int main(){
   string s;
   while(cin >> s){
      if(s == "0000")break;
      int cnt = 0;
      bool flag = false;
      while(s != "6174"){
         if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
            flag = true;
            break;
         }
         cnt++;

         sort(s.begin(),s.end());
         string Min_String = s;
         reverse(s.begin(),s.end());
         string Max_String = s;
         
         stringstream ss(Min_String);
         stringstream ss2(Max_String);
         int Max,Min,value;
         ss >> Min;
         ss2 >> Max;
         s = toString(Max-Min);
         for(int i=0; i<4-s.size(); i++) s += "0";
      }
      if(!flag) cout << cnt << endl;
      else cout << "NA" << endl;
   }
  return 0;
}
