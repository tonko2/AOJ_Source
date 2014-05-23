#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

typedef long long int lli;
int main(){
  int n;
  string s;
  while(cin >> n){
    for(int t=0; t<n; t++){
      deque<pair<string,int> >data1,data2,data3;    
      deque<lli>ans;
      int sp1 = 0,sp2 = 0;
      cin >> s;
      data1.push_back(pair<string,int>("nothing",0));
      data3.push_back(pair<string,int>("nothing",-1));
      for(int i=0; i<s.size()-1; i++){
	if(s[i] == '+') data2.push_back(pair<string,int>("+",1));
	else if(s[i] == '-') data2.push_back(pair<string,int>("-",1));
	else if(s[i] == '*') data2.push_back(pair<string,int>("*",2));
	else if(s[i] == '/') data2.push_back(pair<string,int>("/",2));
	else if(s[i] == '(') data2.push_back(pair<string,int>("(",4));
	else if(s[i] == ')') data2.push_back(pair<string,int>(")",0));
	else{
	  string dummy;
	  for(int j=i; j<s.size()-1; j++){
	    if(isdigit(s[j])) dummy += s[j];
	    else break;
	  }
	  data2.push_back(pair<string,int>(dummy,3));
	  i += dummy.size()-1;
	}
      }

      for(int i=0; i<data2.size(); i++){
	while(data2[i].second <= data1.back().second &&
	      data1.back().first != "("){
	  data3.push_back(data1.back());
	  data1.pop_back();
	}
	if(data2[i].first != ")"){
	  data1.push_back(data2[i]);
	}
	else data1.pop_back();
      }
      
      for(int i=data1.size()-1; i>0; i--)
	data3.push_back(data1[i]);
      
      for(int i=1; i<data3.size(); i++){
	lli value,value2;
	if(data3[i].first == "+"){
	  value = ans.back();
	  ans.pop_back();
	  value2 = ans.back();
	  ans.pop_back();
	  ans.push_back(value2+value);
	}
	
	else if(data3[i].first == "-"){
	  value = ans.back();
	  ans.pop_back();
	  value2 = ans.back();
	  ans.pop_back();
	  ans.push_back(value2-value);
	}
	
	else if(data3[i].first == "/"){
	  value = ans.back();
	  ans.pop_back();
	  value2 = ans.back();
	  ans.pop_back();
	  ans.push_back(value2/value);
	}
	
	else if(data3[i].first == "*"){
	  value = ans.back();
	  ans.pop_back();
	  value2 = ans.back();
	  ans.pop_back();
	  ans.push_back(value2*value);
	}
	
	else{
	  stringstream ss;
	  lli num;
	  ss << data3[i].first;
	  ss >> num;
	  ans.push_back(num);
	}
      }
      cout << (lli)ans.back() << endl; 
    }
  }
  return 0;
}
