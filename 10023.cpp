#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string str,left,right;
  int n,m;
  while(cin >> str){
    if(str == "-")break;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> m;
      left = str.substr(0,m);
      right = str.substr(m,str.size());
      str = right+left;
    }
    cout << str << endl;
  }
  return 0;
}
