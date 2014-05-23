#include <iostream>
using namespace std;

int main(){
  int f[3],j[2];
  int ans = 10000;
  cin >> f[0] >> f[1] >> f[2] >> j[0] >> j[1];

  for(int i=0; i<3; i++){
    for(int k=0; k<2; k++){
      ans = min(ans,f[i] + j[k]);
    }
  }

  cout << ans - 50 << endl;
  return 0;
}


