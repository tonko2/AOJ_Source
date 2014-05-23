#include <iostream>
using namespace std;

int A,B;
int a[5001], b[5001];

int solve(int x){
   int res = 0;
   for(int i=0; i<A; i++){
      if(x == B) break;
      if(a[i] == b[x]){
	 res++;
	 x++;
      }
   }
   return res;
}

int main(){
   cin >> A >> B;
   int ans = 0;

   for(int i=0; i<A; i++) cin >> a[i];
   for(int i=0; i<B; i++) cin >> b[i];
   
   for(int i=0; i<B; i++){
      ans = max(ans,solve(i));
   }

   cout << ans << endl;
   
   return 0;
}
