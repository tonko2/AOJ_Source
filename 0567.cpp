#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;


int main(){
  int n,price1,price2,value,topping[MAX];

  cin >> n;
  cin >> price1 >> price2;
  cin >> value;
  for(int i=0; i<n; i++) cin >> topping[i];

  sort(topping,topping+n);
  reverse(topping,topping+n);

    int a = value, b = price1;
  int ans = value / price1; 
  
  for(int i=0; i<n; i++){
    a += topping[i];
    b += price2; 

    ans = max(ans,a/b);
  }

  cout << ans << endl;
  return 0;
}
