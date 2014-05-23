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
  int n;
  string s;
  map<string,int>m;
  map<string,int>::iterator it;
  cin >> n;
  while(n--){
    m.clear();
    cin >> s;
    string dummy1,dummy2;
    for(int i=1; i<s.size(); i++){
      dummy1 = s.substr(0,i);
      dummy2 = s.substr(i);
      m[dummy1+dummy2]++;
      m[dummy2+dummy1]++;
      string dummy3 = dummy2;
      reverse(dummy3.begin(),dummy3.end());
      string dummy4 = dummy1;
      reverse(dummy4.begin(),dummy4.end());
      m[dummy1+dummy3]++;
      m[dummy3+dummy1]++;
      m[dummy2+dummy4]++;
      m[dummy4+dummy2]++;
      m[dummy3+dummy4]++;
      m[dummy4+dummy3]++;
    }
    int ans = 0;
    for(it=m.begin(); it != m.end(); it++){
      if(it->second > 0)ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
