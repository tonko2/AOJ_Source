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
   int n,t,e;
   while(cin >> n){
      cin >> t >> e;
      for(int i=1; i<=n; i++){
         int T;
         cin >> T;
         for(int j=1; j*T<=t+e; j++){
            if(t - e <= j*T && j*T <= t + e){
               cout << i << endl;
               return 0;
            }
         }
      }
      cout << -1 << endl;
   }
  return 0;
}
