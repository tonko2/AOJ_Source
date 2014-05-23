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

int a,b,c,d,e,f,g,h;

int func1(){
   return a * e + (- b * f)  + (- c * g) + (- d * h);
}

int func2(){
   return a * f + b * e + c * h + (- d * g);
}

int func3(){
   return a * g + (- b * h) + c * e + d * f;
}

int func4(){
   return a * h + (- c * f) + d * e + b * g;
}
int main(){
   int n;
   while(cin >> n && n){
      for(int i=0; i<n; i++){
      cin >> a >> b >> c >> d >> e >> f >> g >> h;
      cout << func1() << " " << func2() << " " << func3() << " "
           << func4() << endl;
      }
   }
  return 0;
}
