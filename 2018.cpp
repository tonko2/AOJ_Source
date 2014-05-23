#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n,m,p;

  while(cin >> n >> m >> p){
    if(n + m + p == 0)break;
    int a[100],ans;
    double sum = 0;
    for(int i=1; i<=n; i++){
      cin >> a[i];
      sum += a[i] * 100;
    }

    if(a[m] == 0)cout << a[m] << endl;
    else{
      sum = sum - sum * ((double)p/100);
      ans = floor(sum / (double)a[m]);
      cout << ans << endl;
    }
  }
  return 0;
}
