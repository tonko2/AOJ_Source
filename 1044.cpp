#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
using namespace std;

typedef long long int lli;

int main(){
  string s,dummy1,dummy2;
  char ope;
  while(cin >> s >> ope){
    bool flag = true;
    dummy1 = dummy2 = "";
    if(ope == 'X')break;
    if(ope == 'U'){
      for(int i=0; i<s.size(); i++){
	s[0] = toupper(s[0]);
	flag = true;
	if(s[i] == '_'){
	  for(int j=0; j<i; j++){
	    dummy1 += s[j];
	  }
	  for(int j=i+1; j<s.size(); j++){
	    if(flag){
	      s[j] = toupper(s[j]);
	      flag = false;
	    }
	    dummy2 += s[j];
	    
	  }
	  dummy1 += dummy2;
	  s = dummy1;
	  dummy1 = dummy2 = "";
	}
      }
    }
    
    else if(ope == 'L'){
      for(int i=0; i<s.size(); i++){
	flag = true;
	s[0] == tolower(s[0]);
	if(s[i] == '_'){
	  for(int j=0; j<i; j++){
	    dummy1 += s[j];
	  }
	  for(int j=i+1; j<s.size(); j++){
	    if(flag){
	      s[j] = toupper(s[j]);
	      flag = false;
	    }
	    dummy2 += s[j];
	  }
	  dummy1 += dummy2;
	  s = dummy1;
	  dummy1 = dummy2 = "";
	}
      }
    }
    
    else{
      for(int i=0; i<s.size(); i++){
	flag = true;
	s[0] = tolower(s[0]);
	if(isupper(s[i])){
	  for(int j=0; j<i; j++){
	    if(flag){
	      s[i] = tolower(s[i]);
	      flag = false;
	    }
	    dummy1 += s[j];
	  }
	  dummy1 += '_';

	  for(int j=i; j<s.size(); j++){
	    dummy2 += s[j];
	  }
	  dummy1 += dummy2;
	  s = dummy1;
	  dummy1 = dummy2 = "";
	}
      }
      for(int i=0; i<s.size(); i++){
	if(islower(s[i])) s[i] = tolower(s[i]);
      }
    }
    cout << s << endl; 
  }

  return 0;
}
