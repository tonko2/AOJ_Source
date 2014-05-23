#include <iostream>
#include <cmath>
using namespace std;

const char moji[5] = {"ixcm"};
const int num[4] = {1,10,100,1000};
int main(){
  int n;
  string s;
  cin >> n;
  for(int i=0; i<n; i++){
    int sum = 0;
    int ans = 0;
    cin >> s;
    for(int j=0; j<s.size(); j++){
      if(isdigit(s[j]) && isalpha(s[j+1])){
	for(int k=0; k<4; k++){
	  if(s[j+1] == moji[k])	sum += (s[j]-'0') * num[k];
	}
	j++;
      }
      else if(isalpha(s[j])){
	for(int k=0; k<4; k++){
	  if(s[j] == moji[k]) sum += num[k];
	}
      }
      else if(isdigit(s[j])){
	sum += s[j] - '0';
      }
    }
    cin >> s;
    int sum2 = 0;
    for(int j=0; j<s.size(); j++){
      if(isdigit(s[j]) && isalpha(s[j+1])){
	for(int k=0; k<4; k++){
	  if(s[j+1] == moji[k])	sum2 += (s[j]-'0') * num[k];
	}
	j++;
      }
      else if(isalpha(s[j])){
	for(int k=0; k<4; k++){
	  if(s[j] == moji[k]) sum2 += num[k];
	}
      }
      else if(isdigit(s[j])){
	sum2 += s[j] - '0';
      }
    }
    ans = sum + sum2;
    string s1;
    for(int k=3; k>=0; k--){
      int dig = ans / num[k];
	ans %= num[k];
      if(dig > 1){
	s1 += dig+'0';
	s1 += moji[k];
      }
      else if(dig == 1) s1 += moji[k];
    }
    cout << s1 << endl;
  }
  return 0;
}
