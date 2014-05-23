#include <iostream>
#include <string>
using namespace std;

int main(){
   int n;
   string str;
   cin >> n;
   cin >> str;
   int ans = 0;
   while(n--){
      string s;
      cin >> s;
      for(int i=1; i<=100; i++){
         bool flag = false;
         for(int j=0; j+i<s.size(); j++){
            int now = 0;
            if(str[now] == s[j]){
               now++;
               int pos = j;
               while(now != str.size() && pos+i<s.size()){
                  if(str[now] == s[pos+i]){
                     pos += i;
                     now++;
                  } else break;
               }
               if(now == str.size()){
                  flag = true;
                  ans++;
                  break;
               }
            }
         }
         if(flag)break;
      }
   }
   cout << ans << endl;
   return 0;
}
