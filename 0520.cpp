#include <iostream>
using namespace std;

typedef long long ll;
ll ok[101],p[101],q[101],r[101],b[101];

ll gcd(ll a, ll b){
   if(b == 0) return a;
   return gcd(b,a%b);
}

ll lcm(ll a, ll b){
   return a * b / gcd(a,b);
}

ll solve(ll x){

   ll left = 1, right = 1;
   if(r[x]) left = solve(r[x]);
   if(b[x]) right = solve(b[x]);

   ll l = lcm(left * p[x], right * q[x]);
   return l / p[x] + l / q[x];
}

int main(){
   ll n;
   while(cin >> n && n){

      fill(ok,ok+101,0);
      
      for(int i=1; i<=n; i++){
	 cin >> p[i] >> q[i] >> r[i] >> b[i];
	 ok[r[i]] = 1;
	 ok[b[i]] = 1;
      }


      for(int i=1; i<=n; i++){
	 if(!ok[i]){
	    cout << solve(i) << endl;
	    break;
	 }
      }
   }
   return 0;
}
