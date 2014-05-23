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

bool G[100][100];
int main(){
   int n,w,h,s,t,cnt,cnt2,ans;
   while(cin >> n && n){
      ans = 0;
      fill(G[0],G[100],false);
      cin >> w >> h;
      for(int i=0; i<n; i++){
         int x,y;
         cin >> x >> y;
         y--,x--;
         G[y][x] = true;
      }
      cin >> s >> t;
      for(int i=0; i<h; i++){
         for(int j=0; j<w; j++){
            cnt = cnt2 = 0;         
            for(int k=i; k<i+t && k<h; k++){
               for(int l=j; l<j+s && l<w; l++){
                  if(G[k][l]) cnt++;
               }
            }
            ans = max(ans,cnt);
         }
      }
      cout << ans << endl;
   }
  return 0;
}
