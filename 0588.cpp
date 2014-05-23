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
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int ans = 0;
   cin >> ans;
   char c;
   int value;
   while(cin >> c){
      if(c == '=')break;
      cin >> value;
      if(c == '-') ans -= value;
      else if(c == '+') ans += value;
      else if(c == '*') ans *= value;
      else if(c == '/') ans /= value;
   }
   cout << ans << endl;
  return 0;
}
