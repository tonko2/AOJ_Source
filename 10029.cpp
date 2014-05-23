#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int ans[MAX];

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> ans[i];

  sort(ans,ans+n);
  for(int i=0; i<n; i++){
    if(i == 0)
      cout << ans[i];
    else
      cout << ' ' << ans[i];
  }
  cout << endl;
  return 0;
}
