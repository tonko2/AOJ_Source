#include <iostream>
#include <stack>
using namespace std;

int main(){
  string s1,s2,s3;
  int cnt=0;
  stack<string>s;
  while(1){
    cin >> s1;
    if(s1 == "quit")break;

    if(s1 == "push"){
      cin >> s2;
      s.push(s2);
    }
    
    if(s1 == "pop"){
      cout << s.top() << endl;
      s.pop();
    }
    
  }
  return 0;
}

