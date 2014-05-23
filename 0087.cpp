#include <iostream>
#include <sstream>
#include <deque>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
  string s,tmp;
  deque<double>deq;
  while(getline(cin,s)){
    deq.clear();
    stringstream ss;
    ss << s;
    while(ss >> tmp){
      double a,b;
      if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
	a = deq.back(),	deq.pop_back();
	b = deq.back(),	deq.pop_back();
	if(tmp == "+")deq.push_back(b+a);
	else if(tmp == "-")deq.push_back(b-a);
	else if(tmp == "*")deq.push_back(b*a);
	else deq.push_back(b/a);
      }
      else deq.push_back(atof(tmp.c_str()));
    }
    cout << fixed << setprecision(6);
    cout << deq.back() << endl;
  }
  return 0;
}
