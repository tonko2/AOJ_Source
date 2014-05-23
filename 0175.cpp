#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;

  while(cin >> n){
    s = "";
    if(n == -1)break;
    int sum = n;
    while(1){
      if(sum < 4){
	s += sum + '0';
	break;
      }
	s += (sum % 4) + '0';
	sum /= 4;
      }
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
  return 0;
}
