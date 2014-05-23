#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef long long ll;
typedef vector<vector<ll> > mat;
const ll mod = 1000000009LL; 

ll H,W,N;

mat multiply(mat A, mat B){
   int n = A.size();
   int m = B[0].size();
   mat res(n,vector<ll>(m,0LL));

   for(int k=0; k<A[0].size(); k++){
      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            res[i][j] +=  (A[i][k] * B[k][j]) % mod;
            res[i][j] %= mod;
         }
      }
   }
   return res;
   
}

void print(mat A){
   int n = A.size();
   int m = A[0].size();
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         cout << A[i][j] << " ";
      }
      cout << endl;
   }
}

mat mod_pow(mat A, ll n){
   
   mat ret(A.size(),vector<ll>(A.size(),0));
   for(int i=0; i<A.size(); i++) ret[i][i] = 1LL;
   if(n == 0) return ret;
   mat tmp = mod_pow(A,n/2);
   tmp = multiply(tmp,tmp);
   if(n & 1) tmp = multiply(tmp,A);
   return tmp;
   
}

int main(){
   int tc = 1;
   while(cin >> W >> H >> N,W|H|N){
      pair<ll,ll>p[100];

      for(int i=0; i<N; i++){
         cin >> p[i].second >> p[i].first;
         p[i].second--,p[i].first--;
      }

      p[N].first = H-1, p[N].second = 0;
      N++;

      sort(p,p+N);

      bool flag = false;
    
      for(int i=0; i<N; i++){
         if(p[i].first == H-1 && p[i].second == W-1) flag = true;
      }

      if(flag){
         cout << "Case " << tc++ << ": " << 0 << endl;
         continue;
      }

    
      mat base(W,vector<ll>(W,0));

      for(int i=0; i<W; i++){
         for(int j=0; j<W; j++){
            if(abs(i-j) <= 1) base[i][j] = 1LL;
         }
      }

      mat line(1,vector<ll>(W,0));
      line[0][0] = 1LL;

      ll now = 0;
      for(int i=0; i<N; ){
         ll y = p[i].first, x = p[i].second;
         ll cnt = y - now;
         mat X = mod_pow(base,cnt);
         line = multiply(line,X);
//         print(line);
         now = y;
         while(i<N && p[i].first == now){
            line[0][p[i++].second] = 0;
         }
      }
      
      cout << "Case " << tc++ << ": ";
      cout << line[0][W-1] << endl;
   }
   return 0;
}
