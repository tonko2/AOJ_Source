#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int a[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
int main(){
  int n;
  string s,dummy;

  cin >> n;
  cin.ignore();

  for(int t=0; t<n; t++){
    getline(cin,s);
    
    for(int i=0; i<12; i++){
      for(int j=0; j<26; j++){
	dummy = s;
	for(int k=0; k<s.size(); k++){
	  if(isalpha(s[k])){
	    dummy[k] = ((a[i] * (s[k]-'a') + j) % 26) + 'a';
	  }
	}
	if(dummy.find("that") != string::npos ||
	   dummy.find("this") != string::npos){
	  cout << dummy << endl;
	  goto end;
	}
      }
    }
  end:;
  }
  return 0;
}
	     
