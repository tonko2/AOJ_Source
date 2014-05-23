#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,x,y,re;
  string s;
  while(cin >> n && n){
    cin >> s;
    vector<int>a,b;
    for(int i=0; i<n; i++){
       int in1,in2;
       cin >> in1 >> in2;
       a.push_back(in1), b.push_back(in2);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0; i<a.size(); i++){
       re = b[i] - a[i];
       x = a[i], y = b[i];
       s[y-1] = 'a' + (s[y-1] - 'a' + re) % 26;
       s[x-1] = 'a' + (s[x-1] - 'a' + re) % 26;
       swap(s[y-1],s[x-1]);
    }
    cout << s << endl;
  }
  return 0;
}
