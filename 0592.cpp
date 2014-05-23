#include <iostream>
using namespace std;

int main(){
   int a[5];
   int ans = 0;
   for(int i=0; i<5; i++){
      cin >> a[i];
      if(a[i] < 40) a[i] = 40;
      ans += a[i];
   }

   ans = ans / 5;
   cout << ans << endl;

   return 0;
}
