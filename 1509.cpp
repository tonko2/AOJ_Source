#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   int a,b,c,d,e;
   int na,nb,nc;
   while(cin >> a >> b >> c >> d >> e,a|b|c|d|e){
      cin >> na >> nb >> nc;
      int ans = nc * c + nb * b + na * a;
      if(nc >= d) ans = min(ans,nc * e + na * a + nb * b);
      else {
         int sum = 0;
         int na2,nb2,nc2;
         for(int i=0; i<d; i++){
            if(nc > 0){
               nc--;
               sum += c;
            } else if(nb > 0){
               nb--;
               sum += b;
            } else if(na > 0){
               na--;
               sum += a;
            }
            ans = min(ans,min(sum,d*e) + na * a + nb * b + nc * c);
         }
      }
      cout << ans << endl;
   }
   return 0;
}
