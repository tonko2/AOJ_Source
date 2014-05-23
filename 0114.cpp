#include <iostream>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
   if(!b) return a;
   return gcd(b,a%b);
}
ll lcm(ll a, ll b){
   return (a*b)/gcd(a,b);
}
int main(){
   int a1,a2,a3,m1,m2,m3,x,y,z;
   ll ans1,ans2,ans3;
   while(cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3,(a1|m1|a2|m2|a3|m3)){
      ans1 = ans2 = ans3 = 0,x = y = z = 1;
      do{
         ans1++;
         x = (a1*x) % m1;
      }while(x!=1);
      do{
         ans2++;
         y = (a2*y) % m2;
      }while(y!=1);

      do{
         ans3++;
         z = (a3*z) % m3;
      }while(z!=1);

      cout << lcm(ans1,lcm(ans2,ans3)) << endl;
   }
   return 0;
}
