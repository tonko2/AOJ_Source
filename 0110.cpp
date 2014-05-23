#include <iostream>
#include <sstream>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
  string s,s1,tmp,total,ans2;
  deque<string>deq;
  int n2,ans;
  while(cin >> s){
    ans = -1;
    for(int i=0; i<=9; i++){
    ans2 = "";
      s1 = s;
      for(int j=0; j<s.size(); j++){
	if(s[j] == 'X') s1[j] = i+'0';
	if(s[j] == '+' || s[j] == '=')  s1[j] = ' ';
      }
      string dummy1,dummy2;
      stringstream ss;
      ss << s1;
      
      while(ss >> tmp) deq.push_back(tmp.c_str());
      total = deq.back();
      deq.pop_back();
      dummy2 = deq.back();
      deq.pop_back();
      dummy1 = deq.back();
      deq.pop_back();
    
      if(dummy1.size() < dummy2.size()){
	reverse(dummy1.begin(),dummy1.end());
	while(dummy1.size() < dummy2.size()){
	  dummy1 += '0';
	}
	reverse(dummy1.begin(),dummy1.end());
      }
      else{
	reverse(dummy2.begin(),dummy2.end());
	while(dummy2.size() < dummy1.size()){
	  dummy2 += '0';
	}
	reverse(dummy2.begin(),dummy2.end());
      }

      int tmp2 = 0,num;
      for(int k=dummy1.size()-1; k>=0; k--){
	num = (dummy1[k]-'0'+dummy2[k]-'0')+tmp2;
	if(num >= 10){
	  tmp2 = 1;
	  num -= 10;
	}
	else tmp2 = 0;
	ans2 += num+'0';
      }
      if(tmp2)
      ans2 += tmp2+'0';
      reverse(ans2.begin(),ans2.end());  

      if(total == ans2){
	ans = i;
	break;
      }
    }
    if(ans==-1) cout << "NA" << endl;
    else cout << ans << endl;
  }
  return 0;
}

