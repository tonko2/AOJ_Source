#include <iostream>
#include <string>
using namespace std;

int main(){
   string a,b,c;
   while(cin >> a){
      if(a == "-")break;
      cin >> b >> c;
      int A = 0, B = 0, C = 0;
      char now = b[B++];
      string ans = "";
      
      while(A < (int)a.size() || B < (int)b.size() || C < (int)c.size()){
	 if(now == c[C] && A < (int)a.size()){
	    C++;
	    now = a[A++];
	 } else {
	    ans += now;
	    now = b[B++];
	 }
      }
      ans += now;
      cout << ans << endl;
      
   }
   return 0;
}
