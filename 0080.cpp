#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int q;
double ans;
void calc(double x){
   if(fabs(x*x*x - q) < 0.00001 * q){
     ans = x;
     return;
   }
   calc(x - (x*x*x-q) / (3*x*x));
 }
int main(){

  while(cin >> q){
    if(q == -1) break;
    calc(q/2.0);
    cout << fixed << setprecision(6);
    cout << ans << endl;
  }
  return 0;
}
