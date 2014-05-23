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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int n,s;
int dp[10][101][1001];

void init(){
   memset(dp,sizeof(dp),0);
   for(int i=0; i<=100; i++) dp[0][i][i] = 1;
   
   for(int i=0; i<8; i++){
      for(int j=0; j<=100; j++){
         for(int k=0; k<=1000; k++){
            if(dp[i][j][k] == 0)continue;
            for(int l=j+1; l<=100; l++){
               if(k + l > 1000)continue;
               dp[i+1][l][k+l] += dp[i][j][k];
            }
         }
      }
   }
}
int main(){
   init();
   while(cin >> n >> s,n|s){
      ll ans = 0;
      for(int i=0; i<=100; i++) ans += dp[n-1][i][s];
      cout << ans << endl;

   }
   return 0;
}
