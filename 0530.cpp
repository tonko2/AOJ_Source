#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1<<29;

int dp[151][1001][80];

void init(){
   
   for(int i=0; i<151; i++)
      for(int j=0; j<1001; j++)
	 for(int k=0; k<80; k++) dp[i][j][k] = INF;
   
   for(int i=0; i<1001; i++)
      for(int j=0; j<80; j++) dp[0][i][j] = 0;
}

int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      init();

      vector<vector<P> >v;
      v.resize(n);

      for(int i=0; i<n; i++){
	 int k;
	 cin >> k;
	 int a,b;
	 for(int j=0; j<k; j++){
	    cin >> a >> b;
	    v[i].push_back(P(a-1,b));
	 }
      }

      for(int i=0; i<v[1].size(); i++){
	 dp[1][v[1][i].first][1] = 0;
      }

      for(int i=0; i<n; i++){
	 for(int j=0; j<=m; j++){
	    for(int k=0; k<(int)v[i].size(); k++){
	       int from_pos = v[i][k].first;
	       int from_cost = v[i][k].second;

	       for(int l=0; i+1 < n && l<(int)v[i+1].size(); l++){
		  int to_pos = v[i+1][l].first;
		  int to_cost = v[i+1][l].second;
		  int c = (from_cost + to_cost) * abs(from_pos-to_pos);
		  dp[i+1][to_pos][j] = min(dp[i+1][to_pos][j],dp[i][from_pos][j]+c);
		  if(j > 0){
		     dp[i+1][to_pos][j] = min(dp[i+1][to_pos][j],dp[i][from_pos][j-1]+c);
		  }
	       }

	       for(int l=0; i+2 < n && l<(int)v[i+2].size(); l++){
		  int to_pos = v[i+2][l].first;
		  int to_cost = v[i+2][l].second;
		  int c = (from_cost + to_cost) * abs(from_pos-to_pos);
		  dp[i+2][to_pos][j+1] = min(dp[i+2][to_pos][j+1],dp[i][from_pos][j]+c);
		  if(j > 0){
		     dp[i+2][to_pos][j+1] = min(dp[i+2][to_pos][j+1],dp[i+2][to_pos][j]);
		  }
	       }
	    }
	 }
      }
      
      int ans = INF;

      for(int i=0; i<1001; i++){
	 for(int j=0; j<=m; j++){
	    ans = min(ans,dp[n-1][i][j]);
	 }
      }

      for(int i=0; i<1001; i++){
	 for(int j=0; j<m; j++){
	    ans = min(ans,dp[n-2][i][j]);
	 }
      }

      cout << ans << endl;

   }
   return 0;
}
