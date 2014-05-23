#include <iostream>
using namespace std;

int main(){
  string s;
  int num1,num2,sum;
  bool flag1,flag2;
  pair<string,int>p[7];
 
  p[0].first = 'I',p[0].second = 1;
  p[1].first = 'V',p[1].second = 5;
  p[2].first = 'X',p[2].second = 10;
  p[3].first = 'L',p[3].second = 50;
  p[4].first = 'C',p[4].second = 100;
  p[5].first = 'D',p[5].second = 500;
  p[6].first = 'M',p[6].second = 1000;
  
  while(cin >> s){
    sum = 0;
    num1 = 0;
    num2 = 0;
    for(int i=0; i<s.size(); i+=2){
      flag1 = false;
      flag2 = false;
      for(int j=0; j<7; j++){
	if(s[i] == p[j].first[0]){
	  num1 = p[j].second;
	  flag1 = true;
	}
	if(s[i+1] == p[j].first[0]){
	  num2 = p[j].second;
	  flag2 = true;
	}
      }
      if(flag1 == false)
	num1 = 0;
      if(flag2 == false)
	num2 = 0;

      if(num1 < num2)
	sum += num2 - num1;
      else if(num1 == num2)
	sum += num1 + num2;
      else{ 
	sum += num1;
	i -= 1;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
