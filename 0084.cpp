#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
  int i=0;
  string s,s2;

  getline(cin,s);
  for(int i=0; i<s.size(); i++){
    if(s[i] == '.' || s[i] == ',')
      s[i] = ' ';
  }

  stringstream ss(s); 

  while(ss >> s2){
    if(s2.size() >= 3 && s2.size() <= 6){
      if(i == 0){
	cout << s2;
	i++;
      }
      else
	cout << ' ' << s2;
    }
  }
  cout << endl;
  return 0;
}
