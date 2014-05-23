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

struct k{
   int p,q,r;
};
int main(){
   int n;
   while(cin >> n && n){
      k data[1001];
      int order[n];
      int id,P,Q,R,C;
      for(int i=0; i<n; i++){
         cin >> id >> P >> Q >> R;
         data[i].p = P;
         data[i].q = Q;
         data[i].r = R;
         order[i] = id;
      }
      cin >> P >> Q >> R >> C;
      bool flag = false;
      for(int i=0; i<n; i++){
         int pp = data[i].p * 4;
         int qq = data[i].q * 9;
         int rr = data[i].r * 4;
         int cc = pp+qq+rr;
         if(P >= data[i].p && Q >= data[i].q  &&
            R >= data[i].r  && C >= cc) flag = true,cout << order[i] << endl;
      }
      if(!flag) cout << "NA" << endl;
   }
  return 0;
}
