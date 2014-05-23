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
   double x,h;
   while(cin >> x >> h && x && h){
      cout << fixed << setprecision(6);
      cout << x*x + sqrt(x*x/4 + h*h) * x / 2 * 4 << endl;
   }
  return 0;
}
