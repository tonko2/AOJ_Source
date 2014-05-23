#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  int count;

  while(1){
    getline(cin,s);
    if(s == "END OF INPUT")break;
    count = 0;
    for(int i=0; s[i] != '\0'; i++){
      count++;
      if(s[i] == ' '){
	cout << (count-1);
	count = 0;
      }
      else if(s[i+1] == '\0')
	cout << count;
    }
    cout << endl;
  }
  return 0;
}

