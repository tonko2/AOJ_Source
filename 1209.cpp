#include <iostream>
#include <vector>
using namespace std;

const int MAX = 289;
int dp[MAX+1];
vector<int>v;
int main(){
   for(int i=1; i*i <=289; i++) v.push_back(i*i);
   int n;

   dp[0] = 1;
   for(int i=0; i<v.size(); i++){
      for(int j=v[i]; j<=MAX; j++){
         dp[j] += dp[j-v[i]];
      }
   }
   while(cin >> n && n){
      cout << dp[n] << endl;
   }
   return 0;
}
