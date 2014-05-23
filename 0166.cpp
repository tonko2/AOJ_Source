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
  int n,m;
  double theta[1000],S1,S2;
  while(cin >> n && n){
    fill(theta,theta+1000,0);
    S1 = S2 =  0;
    for(int i=0; i<n-1; i++){
      cin >> theta[i];
      theta[n-1] += theta[i];
    }
    theta[n-1] = 360-theta[n-1];

    for(int i=0; i<n; i++) S1 += sin(acos(-1)*theta[i]/180.0);

    fill(theta,theta+1000,0);
    cin >> m;
    for(int i=0; i<m-1; i++){
      cin >> theta[i];
      theta[m-1] += theta[i];
    }
    theta[m-1] = 360-theta[m-1];

    for(int i=0; i<m; i++) S2 += sin(acos(-1)*theta[i]/180.0);

    if(S1 == S2) cout << 0 << endl;
    else if(S1 > S2) cout << 1 << endl;
    else cout << 2 << endl;
  }
  return 0;
}
