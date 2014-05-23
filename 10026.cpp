#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAX_N = 1000;

int main(){
  int n,sum;
  double avg,ans,sum2;
  int a[MAX_N];
  while(cin >> n && n){
    sum = 0;
    sum2 = 0;
    for(int i=0; i<n; i++){
      cin >> a[i];
      sum += a[i];
    }
    avg = (double)sum / n; 
    for(int i=0; i<n; i++){
      sum2 += pow(a[i]-avg,2);
    }
    ans = sqrt(sum2 / n);

    cout << fixed << setprecision(8);
    cout << ans << endl;
  }
  return 0;
}



 
