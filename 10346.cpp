#include <iostream>
using namespace std;

int main(){
  int n,k;

  while(cin >> n >> k && (n|k)){
    int ans = n;
    int tmp = 0;
    while(n < k){
      n = n / k;
      ans += n;
    }
    cout << ans << endl;
  }
  return 0;
}
