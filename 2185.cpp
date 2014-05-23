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
  int n,X,Y,W,H,x,y;
  int sx,sy,gx,gy,num,ans;
  cin >> n;
  for(int i=0; i<n; i++){
    ans = 0;
    cin >> X >> Y >> H >> W;
    sx=X,sy=Y,gx=X+W,gy=Y+H;
    cin >> num;
    for(int j=0; j<num; j++){
      cin >> x >> y;
      if(sx <= x && sy <= y && gx >= x && gy >= y)ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
