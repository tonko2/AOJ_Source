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
   int n;
   int S[101];
   while(cin >> n && n){
      memset(S,0,sizeof(S));
      for(int i=0; i<n; i++){
         int a,b,c,d,e;
         cin >> a >> b >> c >> d >> e;
         S[i] = a + b + c + d + e;
      }
      sort(S,S+n);
      cout << S[n-1] << " " << S[0] << endl;
   }
  return 0;
}
