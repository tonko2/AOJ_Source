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
   int sum = 0;
   for(int i=0; i<10; i++){
      int in;
      cin >> in;
      sum += in;
   }
   cout << sum << endl;
  return 0;
}
