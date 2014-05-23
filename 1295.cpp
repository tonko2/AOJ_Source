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
#include <cctype>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int w,d;
   while(cin >> w >> d,w|d){
      int W[w],D[d];
      int ans = 0;
      for(int i=0; i<w; i++) cin >> W[i];
      for(int i=0; i<d; i++) cin >> D[i];

      sort(W,W+w);
      sort(D,D+d);
      
      for(int i=0; i<w; i++){
         for(int j=0; j<d; j++){
            if(W[i] == D[j]){
               D[j] = 0;
               break;
            }
         }
      }

      for(int i=0; i<w; i++) ans += W[i];
      for(int i=0; i<d; i++) ans += D[i];

      cout << ans << endl;
   }
  return 0;
}
