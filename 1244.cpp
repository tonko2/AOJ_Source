#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

string s;
map<string,int>m;
int pos;
bool flag = false;
int exp();

int parseNum(){
   string str = "";
   while(s[pos] >= '0' && s[pos] <= '9') str += s[pos++];
   if(str == "") return 1;
   else return atoi(str.c_str());
}

string f(){
   string res = "";
   if(s[pos] >= 'A' && s[pos] <= 'Z') res += s[pos++];
   if(s[pos] >= 'a' && s[pos] <= 'z') res += s[pos++];
   return res;
}

int term(){
   int res = 0;
   if(s[pos] == '('){
      pos++;
      int e = exp();
      int num = parseNum();
      return e * num;
   }
   string atom = f();
   int num = parseNum();
   if(!m.count(atom)){
      pos = s.size();
      flag = true;
      return 0;
   }

   res = m[atom] * num;
  
   return res;
}

int exp(){
   int res = term();
   while(pos < s.size()){
      if(s[pos] == ')'){
         pos++;
         break;
      }
      res += term();
   }
   return res;
}

int main(){
   while(cin >> s){
      if(s == "END_OF_FIRST_PART")break;
      int in;
      cin >> in;
      m[s] = in;
   }

   while(cin >> s){
      if(s == "0")break;
      flag = false;
      pos = 0;
      int ans = exp();
      if(flag) cout << "UNKNOWN" << endl;
      else cout << ans << endl;
   }
   return 0;
}
