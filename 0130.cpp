#include <iostream>
#include <deque>
using namespace std;

int main(){
  int n,now;
  string s,s1;
  deque<char>deq;
  cin >> n;
  for(int i=0; i<n; i++){
    now = 0;
    cin >> s;
    deq.clear();
    deq.push_back(s[0]);
    for(int j=1; j<s.size(); j++){
      bool flag = false;
      if(s[j] == '-'){
	for(int k=0; k<deq.size(); k++){
	  if(deq[k] == s[j+2])flag = true;
	}
	if(!flag)
	deq.push_back(s[j+2]);
	now += 1;
	j+=2;
      }
      else if(s[j] == '<'){
	for(int k=0; k<deq.size(); k++){
	  if(deq[k] == s[j+2])flag = true;
	}
	if(!flag)
	  deq.push_front(s[j+2]);
	now -= 1;
	j += 2;
      }
    }
    for(int j=0; j<deq.size(); j++)
      cout << deq[j];
    cout << endl;
  }
  return 0;
}
