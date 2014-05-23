#include <iostream>
#include <map>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> Pi;

int main(){
   int n,h;
   while(cin >> n >> h,n|h){
      map<Pi,int>m;
      string s;
      int in,in2;

      for(int j=0; j<h; j++){
         cin >> s >> in >> in2;
         if(s == "xy"){
            for(int i=n; i>=1; i--){
               Pi p;
               p.first.first = in, p.first.second = in2;
               p.second = i;
               m[p] = 1;
            }
         }

         if(s == "xz"){
            for(int i=n; i>=1; i--){
               Pi p;
               p.first.first = in, p.second = in2;
               p.first.second = i;
               m[p] = 1;
            }
         }

         if(s == "yz"){
            for(int i=n; i>=1; i--){
               Pi p;
               p.first.first = i, p.first.second = in;
               p.second = in2;
               m[p] = 1;
            }
         }
      }
      map<Pi,int>::iterator it;
      
      cout << n*n*n-m.size() << endl;
   }
   return 0;
}
