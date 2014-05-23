#include <iostream>
using namespace std;

int main(){
  double a1,a2,a3,a4,b1,b2,b3,b4;

  while(cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4){
    if(b1 <= a3 && b2 <= a4 && a1 <= b3 && a2 <= b4) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
