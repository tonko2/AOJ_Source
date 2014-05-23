#include <iostream>
using namespace std;

int main(){
  char ch,a = 'a';
  int ans[26];
  fill(ans,ans+26,0);
  while(cin >> ch){
    ch = tolower(ch);
    int num = ch - 'a';
    ans[num]++;
  }
  for(int i=0; i<26; i++){
    cout << a++  << ' ' << ':' << ' ' << ans[i] << endl;
  }
  return 0;
}

