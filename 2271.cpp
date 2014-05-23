#include <iostream>
using namespace std;

int main(){
  string s;
  int k=0,u=0,p=0,c=0;
  int a,b,ans;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    if(s[i] == 'K')
      k++;
    if(s[i] == 'U')
      u++;
    if(s[i] == 'P')
      p++;
    if(s[i] == 'C')
      c++;
  }

  a = min(k,u);
  b = min(p,c);
  ans = min(a,b);

  cout << ans << endl;

  return 0;
}
