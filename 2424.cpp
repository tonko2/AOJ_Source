#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

int main(){
   int n;
   string s;
   while(cin >> n && n){
      for(int t=0; t<n; t++){
         int res = 0;
         cin >> s;
         while(s.size() > 1){
            res++;
            int Max = -1;
            for(int i=1; i<s.size(); i++){
               int left = atoi(s.substr(0,i).c_str());
               int right = atoi(s.substr(i,s.size()).c_str());
               Max = max(Max,left*right);
            }
            ostringstream os;
            os << Max;
            s = os.str();
         }
         cout << res << endl;
      }
   }
   return 0;
}
