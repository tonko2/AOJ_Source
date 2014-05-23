#include <iostream>
#include <string>

using namespace std;

int pos;
string s;

int NOT();
int term();
int exp();

int factor(){
   int x;
   if(s[pos] == '('){
      pos++;
      x = exp();
      pos++;
   } else {
      x = s[pos] - '0';
      pos++;
   }
   return x;
}
int NOT(){
   int x;
   if(s[pos] == '-'){
      pos++;
      x = 2 - NOT();
   } else {
      x = factor();
   }
   return x;
}
int term(){
   int x = NOT();
   while(s[pos] == '*'){
      pos++;
      x = min(x,NOT());
   }
   return x;
}

int exp(){
   int x = term();
   while(s[pos] == '+'){
      pos++;
      x = max(x,term());
   }
   return x;
}
int solve(string st){
   int ans = 0;
   for(char p='0'; p<='2'; p++){
      for(char q='0'; q<='2'; q++){
         for(char r='0'; r<='2'; r++){
            s = st;
            for(int i=0; i<st.size(); i++){
               if(s[i] == 'P') s[i] = p;
               if(s[i] == 'Q') s[i] = q;
               if(s[i] == 'R') s[i] = r;
            }
            pos = 0;
            if(exp() == 2) ans++;
         }
      }
   }
   return ans;
}
int main(){
   string str;
   while(cin >> str && str != "."){
      cout << solve(str) << endl;
   }
   return 0;
}
