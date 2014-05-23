#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toStr(int a){
   ostringstream oss;
   oss << a;
   return oss.str();
}

int toInt(string s){
   stringstream ss;
   ss << s;
   int num;
   ss >> num;
   return num;
}

int main(){
   int x;
   while(cin >> x){
      string num = toStr(x);
      int ans = 0;
      for(int i=0; i<=num.size()/2; i++){
         string tmp = num.substr(0,i);
         if(i == 0) tmp = "0";
         string tmp2 = num.substr(i,num.size());
         if(i == 0) tmp2 = num.substr(i,num.size());
         if(tmp2[0] == '0')continue;

         int x = toInt(tmp);
         int y = toInt(tmp2);

         if(x > y)continue;
         if((y-x) % 2 == 0 && (x+y) % 2 == 0){
            ans++;
         }
      }
      cout << ans << endl;
      
   }
   return 0;
}
