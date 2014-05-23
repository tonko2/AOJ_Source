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
using namespace std;

typedef long long int lli;
deque<char>deq[1001];
int main(){
  int n,pos,num,num2;
  string s;
  char color;
  cin >> n;
  while(cin >> s){
    if(s == "quit")break;
    if(s.find("push",0) != string::npos){
      cin >> num >> color;
      deq[num].push_back(color);	
    }
    else if(s.find("pop",0) != string::npos){
      cin >> num;
      cout << deq[num].back() << endl;
      deq[num].pop_back();
    }
    else if(s.find("move",0) != string::npos){
      cin >> num >> num2;
      deq[num2].push_back(deq[num].back());
      deq[num].pop_back();
    }
  }
  return 0;
}
