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

const int TURN = 131;
const int MAX_N = 131;

int main(){
   int n,t,l,b;
   while(cin >> n >> t >> l >> b,n|t|l|b){
      double dp[TURN][MAX_N];
      fill(dp[0],dp[TURN],0);

      dp[0][0] = 1.0;
      
      bool usedL[MAX_N];
      bool usedB[MAX_N];
      fill(usedL,usedL+MAX_N,0);
      fill(usedB,usedB+MAX_N,0);
      for(int i=0; i<l; i++){
         int in;
         cin >> in;
         usedL[in] = true;
      }


      for(int i=0; i<b; i++){
         int in;
         cin >> in;
         usedB[in] = true;
      }
      
      for(int i=0; i<t; i++){
         for(int j=0; j<n; j++){
            for(int k=1; k<=6; k++){
               int next = j + k;
               int ni = i+1;
               if(j+k > n) next = 2*n-(j+k);
               if(usedB[next]) next = 0;
               else if(usedL[next]) ni++;
               dp[ni][next] += dp[i][j]/6;
            }
         }
      }
      double ans = 0;
      for(int i=0; i<=t; i++) ans += dp[i][n];
      printf("%.6f\n",ans);
   }

  return 0;
}
