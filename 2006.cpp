#include <iostream>
using namespace std;

const char me[10][6] = {"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv",
			"wxyz"};

int main(){
  int n;
  string s;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s;
    int count = 0;
    for(int j=0; j<s.size(); j++){
      if(s[j] != '0')
	count++;

      else if(s[j] == '0' && count == 0)continue;

      else if(s[j] == '0'){
	if(s[j-1] == '1' && count > 5){
	  count %= 5;
	  if(count == 0)count = 5;
	}
	else if(count > 4 && (s[j-1] == '7' || s[j-1] == '9')){
	  count %= 4;
	  if(count == 0)count = 4;
	}	
	
	else if(count > 3 && (s[j-1] == '2' || s[j-1] == '3' || s[j-1] == '4' ||
			      s[j-1] == '5' || s[j-1] == '6' || s[j-1] == '8'))
	  count %= 3;
	if(count == 0)count=3;
	cout << me[s[j-1]-'0'][count-1];
	count = 0;
      }
    } 
    cout << endl; 
  }
  return 0;
}
