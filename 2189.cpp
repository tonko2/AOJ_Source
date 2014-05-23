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
const char ans[3][11] = {"Audrey wins.","Fabre wins"};
int n;
string s,dummy,dummy1,dummy2,ans;


void dfs(int first, int last){
  if(dummy.size() == 1 && dummy != "0") return true;
  int a,b;
  string c;
  a = dummy[first]-'0';
  b = dummy[last]-'0';
  sprintf(c,"%s",a+b);
    for(int j=0; j<first; j++)dummy1 += dummy[j];
    for(int j=last; j<dummy.size(); j++) dummy2 += dummy[j];
    ans += dummy1;
    ans += c;
    ans += dummy2;
    dummy = ans;
}
int main(){
 

  for(int t=0; t<n; t++){
    cin >> s;
    dummy1 = "";
    dummy2 = "";
    bool flag = false;
    for(int i=0; i<s.size()-1; i++){
      dummy = s;
      if(dfs(i,i+1)){
	flag = true;
	break;
      }
    }
    if(flag) cout << ans[0] << endl;
    else cout << ans[1] << endl;
  }
  return 0;
}
