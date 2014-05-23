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

const int MAX = 1000000;
typedef long long ll;
typedef pair<int,int> P;
int main(){
   int n,a,b,cnt;
   while(cin >> n >> a >> b,n|a|b){
      cnt = 0;
      n++;
      vector<bool>v(n);
      v[0] = true;
      if(a < n)v[a] = true;
      if(b < n)v[b] = true;
      for(int i=0; i<n; i++){
         if(!v[i]) cnt++;
         else {
            if(a+i < n) v[a+i] = true;
            if(b+i < n) v[b+i] = true;
         }
      }
      cout << cnt << endl;
   }
  return 0;
}
