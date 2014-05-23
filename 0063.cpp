#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  string s,t;
  int cnt = 0;
  while(cin >> s){
    t = s;
    reverse(t.begin(),t.end());
    if(s == t)cnt++;
  }
  cout << cnt << endl;
  return 0;
}
