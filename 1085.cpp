#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 20000;
int data[MAX_N];
int main(){
  int n,s;

  while(cin >> n >> s && (n|s)){
    fill(data,data+MAX_N,1000);
    for(int i=0; i<n; i++) cin >> data[i];
    sort(data,data+n);

    int pos,ans=0;
    for(int i=0; i<n; i++){
      pos = &data[n] - upper_bound(data+i+1,data+n,s-data[i]);
      if(pos == n)continue;
      ans += pos;
    }
    cout << ans << endl;
  }
  return 0;
}
