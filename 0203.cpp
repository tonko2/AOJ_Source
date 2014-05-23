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

const int MAX = 15;
typedef long long ll;
typedef pair<int,int> P;

int field[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];
int main(){
   int h,w;
   while(cin >> w >> h,w|h){
      memset(dp,0,sizeof(dp));
      for(int i=0; i<h; i++)
         for(int j=0; j<w; j++) cin >> field[i][j];

      for(int i=0; i<w; i++)
         if(field[0][i] != 1) dp[0][i] = 1;


      for(int i=0; i<h; i++){
         for(int j=0; j<w; j++){
            if(dp[i][j] == 0)continue;
            if(field[i][j] == 2){
               int nowy = i + 2;
               if(nowy >= h) continue; 
               if(field[nowy][j] == 1) continue;
               dp[nowy][j] += dp[i][j];
            } else {
               for(int k=-1; k<=1; k++){
                  int ny = i + 1, nx = j + k;
                  if(ny >= h || nx < 0 || nx >= w) continue;
                     if(field[ny][nx] == 1) continue;
                     else if(field[ny][nx] == 2 && k != 0) continue;
                     dp[ny][nx] += dp[i][j];
                     }
               }
            }
         }
         
         int ans = 0;
         for(int i=0; i<w; i++){
            if(field[h-2][i] == 2) ans += dp[h-2][i];
            if(field[h-1][i] != 1) ans += dp[h-1][i];
         }
         cout << ans << endl;
      }
      return 0;
   }
