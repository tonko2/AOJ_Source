#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,a[100],value;
  while(cin >> n && n){
    int cnt = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> value;
    sort(a,a+n);

    int left,right;
    left = 0;
    right = n-1;
    while(left <= right){
      cnt++;
      if(a[(left+right)/2] == value) break;

      if(a[(left+right)/2] > value) right = (left+right)/2-1; 
      else if(a[(left+right)/2] < value)left = (left+right)/2+1;
    }
    cout << cnt << endl;
  }
  return 0;
}
