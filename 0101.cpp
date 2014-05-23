#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  int n;

  cin >> n;
  cin.get();
  for(int i=0; i<n; i++){
    getline(cin,s);
    for(int j=0; s[j] != '\0'; j++){
      if(s[j] == 'H' && s[j+1] == 'o' && s[j+2] == 's' && s[j+3] == 'h' &&
	 s[j+4] == 'i' && s[j+5] == 'n' && s[j+6] == 'o')
	  s[j+6] = 'a';
    }
    cout << s << endl;     
  }
  return 0;
}
