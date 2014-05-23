#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
   string s;
   string ope,left,right;
   while(cin >> ope >> left >> right){
      string ans;
      int n = left.size();
      int m = right.size();
      
      if(ope == "i"){
         int l = 0, r = 0;
         while(true){
            if(l == n && r == m)break;
            if(l < n && r < m && left[l] == right[r]){
               ans += left[l];
               l++,r++;
            } else if(l < n && left[l] == '('){
               l += 3;
            }
            else if(r < m && right[r] == '(') r += 3;
            else if(r < m) r++;
            else if(l < n)l++;
         }
      } else {
         int l = 0, r = 0;
         while(true){
            if(l == n && r == m)break;
            if(l < n && r < m && left[l] == right[r]){
               ans += left[l];
               l++,r++;
            } else if(l < n && left[l] == '('){
               ans += left[l];
               l++;
            }
            else if(r < m && right[r] == '('){
               ans += right[r];
               r++;
            } else if(r < m){
               ans += right[r];
               r++;
            } else {
               ans += left[l];
               l++;
            }
         }
      }
      cout << ans << endl;
   }
   return 0;
}
