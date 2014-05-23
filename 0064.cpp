#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n=0,sum=0;
  string s;
  while(cin >> s){
    //    getline(cin,s);
    //    if(cin.eof())break;

    for(int i=0; s[i] != '\0'; i++){
      if(s[i] >= '0' && s[i] <= '9'){
	n *= 10;
	n += s[i] - '0';
      }else{
	sum += n;
	n = 0;
      }
    }
  }
  cout << sum << endl;
  return 0;
}

    
