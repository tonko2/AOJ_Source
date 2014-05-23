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

bool hours[25];

int main(){
   int N,n;
   while(cin >> N && N){
      fill(hours,hours+25,0);
      int n,ans = 0;
      cin >> n;
      for(int i=0; i<n; i++){
         int s,e;
         cin >> s >> e;
         ans += e - s;
      }
      if(ans >= N) cout << "OK" << endl;
      else cout << N - ans << endl;
   }
  return 0;
}
