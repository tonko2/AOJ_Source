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
typedef pair<int,int> P;
const double PI = acos(-1);
const int INF = 1 << 30;
int G[5][5],ans;

void solve(){    
   for(int i=0; i<5; i++){
      for(int j=3; j>=0; j--){
         if(G[i][j]){
            G[i][j] = G[i][j+1]+1;
         }
      }
   }
   for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
         int k=i,cnt=1,MIN_H=INF;
         while(G[k][j] && k != 5){
            MIN_H = min(MIN_H,G[k][j]);
            ans = max(ans,cnt*MIN_H);
            cnt++,k++;
         }
      }
   }
}
int main(){
   int n,in;
   cin >> n;
   for(int i=0; i<n; i++){
      ans = 0;
      for(int j=0; j<5; j++){
         for(int k=0; k<5; k++){
            cin >> G[j][k];
         }
      }
      solve();
//      cin.ignore();
      cout << ans << endl;
   }
   return 0;
}
