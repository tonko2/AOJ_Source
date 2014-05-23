#include <iostream>
using namespace std;

int const MAX_N = 5000;
int n,a[MAX_N],Max,sum;

void solve(){
  Max = a[0];
  for(int i=0; i<n; i++){
    sum = 0;
    for(int j=i; j<n; j++){
      sum += a[j];
      Max = max(Max,sum);
    }
  }
  cout << Max << endl;
}
int main(){
  while(cin >> n,n){
    for(int i=0; i<n; i++)
      cin >> a[i];
    solve();
  }
  return 0;
}
    
