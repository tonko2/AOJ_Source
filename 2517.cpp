#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)
const int MAX = 60;
const int INF = 1<<29;
int dp[MAX][MAX];
int prev[MAX][MAX];
int in[MAX][MAX];

int main(){
   int p,m;
   cin >> p >> m;

   int tmp[MAX][MAX];
   rep(i,p)
      rep(j,m) cin >> tmp[i][j];

   rep(i,m)
      rep(j,p) in[i][j] = tmp[j][i];

   fill(dp[1],dp[MAX],INF);
   fill(prev[0],prev[MAX],-1);


   rep(i,m){
      rep(j,p){
         rep(k,p){
            if(dp[i+1][k] > dp[i][j] + in[i][k]){
               dp[i+1][k] = dp[i][j] + in[i][k];
               prev[i+1][k] = j;
            } else {
               if((dp[i+1][k] ==  (dp[i][j] + in[i][k])) && j == k){
                  prev[i+1][k] = j;
               }
            }
         }
      }
   }
   
   int minMove = 0, ans = 1<<29;
   int First = 0;

   vector<int>v;
   
      rep(i,p){
         if(ans >=dp[m][i]){
            ans = dp[m][i];
         }
      }

      rep(i,p){
         if(ans == dp[m][i]) v.push_back(i);
      }
      
      vector<pair<int,vector<int> > >paths;
      int c = 0;
      while(c != v.size()){
         minMove = 0;
         First = v[c];
         c++;
         vector<int>path;
         path.push_back(First);
         
         for(int cnt=m; cnt>=2; cnt--){
            int nowPath = First;
            First = prev[cnt][First];
            path.push_back(First);
            if(First != nowPath) minMove++;
         }
         reverse(path.begin(),path.end());
         pair<int,vector<int> >pp;
         pp.first = minMove;
         pp.second = path;
         paths.push_back(pp);
      }

      sort(paths.begin(),paths.end());
      minMove = paths[0].first;

      vector<int>vv;
      vv = paths[0].second;
      cout << ans << " " << minMove << endl;


      rep(i,vv.size()){
         cout << vv[i]+1 << endl;
      }
   
   return 0;
}
