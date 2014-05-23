#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;
ll exp();
ll term();
ll factor();

string s;
int pos,p;
bool f;

ll extgcd(ll a, ll b, ll& x, ll& y){
  ll d = a;
  if(b != 0){
    d = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
  }else{
    x = 1; y = 0;
  }
  return d;
}

ll mod_inverse(ll a, ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

ll factor(){
   ll res = 0;
   if(s[pos] == '('){
      pos++;
      res = exp();
      pos++;
   }

   while(s[pos] >= '0' && s[pos] <= '9'){
      res *= 10LL;
      res += s[pos] - '0';
      pos++;
   }
   return res;
}

ll term(){
   ll res = factor();

   while(s[pos] == '*' || s[pos] == '/'){
      if(s[pos] == '*'){
         pos++;
         res = (res * factor()) % p;
      }
      
      if(s[pos] == '/'){
         pos++;
         ll y = factor();
         if(y == 0){
            f = false;
            pos = 10000;
            return 0;
         }
         ll d = mod_inverse(y,p);
         res = (res * d) % p;
      }
   }
   return res;
}

ll exp(){
   ll res = term();
   while(s[pos] == '+' || s[pos] == '-'){
      if(s[pos] == '+'){
         pos++;
         res = (res + term()) % p;
      }
      if(s[pos] == '-'){
         pos++;
         res = (res + p - term()) % p;
      }
   }
   return res;
}

int main(){
   while(getline(cin,s)){
      string str;
      for(ll i=0; i<s.size(); i++){
         if(s[i] == ':'){
            s[i] = ' ';
            break;
         }
         str += s[i];
         s[i] = ' ';
      }
 
      stringstream ss;
      ss << str;
      ss >> p;
 
      if(p == 0)break;
 
      string s2;
      for(ll i=0; i<s.size(); i++){
         if(s[i] == ' ')continue;
         s2 += s[i];
      }
      pos = 0;
      f = true;
      ll ans = -1;
      s = s2;
      ans = exp() % p;
      if(!f) cout << "NG" << endl;
      else cout << s2 << " = " << ans << " (mod " << p << ")" << endl;
   }
   return 0;
}
