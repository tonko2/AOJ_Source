#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v;
const int MAX = 1000003;
void init(){
   bool used[MAX+1];
   fill(used,used+MAX+1,true);
   for(int i=2; i<=MAX; i++){
      if(used[i]){
         v.push_back(i);
         for(int j=2*i; j<=MAX; j+=i){
            used[j] = false;
         }
      }
   }
}
int main(){
   init();
   int n;
   while(cin >> n && n){
      int ans = 0;
      for(int i=0; i<n; i++){
         int p,m;
         cin >> p >> m;
         int Max = min(999983,p+m);
         int Min = max(0,p-m);
         int X = upper_bound(v.begin(),v.end(),Max) - lower_bound(v.begin(),v.end(),Min);
         if(X == 0) ans--;
         else ans += X - 1;
      }
      
      cout << ans << endl;
   }
   return 0;
}
