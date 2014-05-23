#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
   int N,K;
   while(cin >> N >> K){
      
      int dp[12][2001];
      fill(dp[0],dp[11],0);
      vector<int> v[10], price[10];

      for(int i=0; i<N; i++){
	 int a,b;
	 cin >> a >> b;
	 v[b-1].push_back(a);
      }

      for(int i=0; i<10; i++){
	 sort(v[i].begin(),v[i].end(),greater<int>());
	 int sum = 0;
	 price[i].push_back(0);
	 for(int j=0; j<v[i].size(); j++){
	    sum += v[i][j];
	    price[i].push_back(sum + j * (j+1));
	 }
      }

      for(int i=0; i<10; i++){
	 for(int j=0; j<price[i].size(); j++){
	    for(int k=0; k+j<=K; k++){
	       if(j) dp[i+1][k+j] = max(dp[i+1][k+j],dp[i][k]+price[i][j]);
	       else dp[i+1][k+j] = dp[i][k+j];
	    }
	 }
      }

      cout << dp[10][K] << endl;
      
   }
   return 0;
}
