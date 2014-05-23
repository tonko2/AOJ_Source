#include <iostream>
using namespace std;

int main(){
  string s1,s2;

  cin >> s1;
  for(int i=0; i<s1.size(); i++)
    s1[i] = tolower(s1[i]);
  int count = 0;
  while(cin >> s2){
    for(int i=0; i<s2.size(); i++)
      s2[i] = tolower(s2[i]);

    if(s2 == "END_OF_TEXT")break;
    if(s1 == s2)count++;
  }
  cout << count << endl;
return 0;
}
