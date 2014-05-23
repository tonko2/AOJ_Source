#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 24;
int X[MAX],Y[MAX],R[MAX],C[MAX];
short memo[1<<24];
short n;

bool check(int i, int j){
   double x = X[i], y = Y[i];
   double x2 = X[j], y2 = Y[j];
   return sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2)) < R[i] + R[j];
}

bool hit(int x, int bit){
   for(int i=0; i<x; i++){
      if((1<<i) & bit){
         if(check(x,i)) return false;
      }
   }
   return true;
}

int dfs(int bit){
   if(memo[bit] != -1) return memo[bit];
   int ans = 0;
   
   for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
         if((bit & (1<<i)) && (bit & (1<<j)) && C[i] == C[j] && hit(i,bit) && hit(j,bit)){
            int next = bit & (~(1<<i)) & (~(1<<j));
            ans = max(ans,dfs(next)+2);
         }
      }
   }
   
   return memo[bit] = ans;
}
int main(){

   while(cin >> n && n){
      for(int i=0; i<n; i++) cin >> X[i] >> Y[i] >> R[i] >> C[i];
      memset(memo,-1,sizeof(memo));
      cout << dfs((1<<n)-1) << endl;
   }
   return 0;
}
