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
int ans = -1;
void dfs(bool flag, string s){
   if(ans != -1) return;
   int cnt = 0,cnt2 = 0;
   string dummy;
   if(flag == true){
      if(s[0] == 'o' && s[s.size()-1] == 'o') flag = false;
   }
   if(flag == false){
      if(s[0] == 'x' && s[s.size()-1] == 'x') flag = true;
   }
   for(int i=0; i<s.size(); i++){
      if(s[i] == 'x')cnt++;
      if(s[i] == 'o')cnt2++;
   }
   if(cnt == s.size()){
      ans = 1;
      return;
   } else if(cnt2 == s.size()){
      ans = 0;
      return;
   }
   if(s[0] == 'x' && flag == true){
      for(int i=0; i<s.size(); i++){
         if(s[i] == 'x') s[i] = 'o';
         else {
            dummy = s;
            reverse(s.begin(),s.end());
            s += 'o';
            reverse(s.begin(),s.end());
            flag = false;
            dfs(flag,s);
            s = dummy;
         }
      }
   }
   if(s[s.size()-1] == 'x' && flag == true){
      for(int i=s.size()-1; i>=0; i--){
         if(s[i] == 'x') s[i] = 'o';
         else{
            dummy = s;
            s += 'o';
            flag = false;
            dfs(flag,s);
            s = dummy;
         }
      }
   }
   if(s[0] == 'o' && flag == false){
      for(int i=0; i<s.size(); i++){
         if(s[i] == 'o') s[i] = 'x';
         else {
            dummy = s;
            reverse(s.begin(),s.end());
            s += 'x';
            reverse(s.begin(),s.end());
            flag = true;
            dfs(flag,s);
            s = dummy;
         }
      }
   }
   if(s[s.size()-1] == 'o' && flag == false){
      for(int i=s.size()-1; i>=0; i--){
         if(s[i] == 'o') s[i] = 'x';
         else{
            dummy = s;
            s += 'x';
            flag = true;
            dfs(flag,s);
            s = dummy;
         }
      }
   }
}
int main(){
   string s;
   bool flag = true; //true is o false is x
   cin >> s;
   dfs(flag,s);
   if(ans == 0) cout << 'o' << endl;
   else cout << 'x' << endl;
   return 0;
}
