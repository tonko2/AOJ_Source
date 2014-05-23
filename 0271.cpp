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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
 
const int MAX = 100001;
const int MOD = 1000000007;
ll F[MAX];
int bit[MAX];
int n;

void f(){
   F[0] = 1;
   for(ll i=1; i<MAX; i++) F[i] = (F[i-1]*i) % MOD;
}

ll sum(int i){
   ll s = 0;
   while(i > 0){
      s += bit[i];
      i -= i&-i;
   }
   return s;
}

void add(int i, int x){
   while(i <= n){
      bit[i] += 1;
      i += i&-i;
   }
}

int main(){
   int m;
   ll a[MAX];
   f();
   
   while(cin >> n,n){
      cin >> m;
      for(int i=0; i<n; i++) a[i] = i+1;
   
      for(int i=0; i<m; i++){
         int in,in2;
         cin >> in >> in2;
         swap(a[in-1],a[in2-1]);
      }

      fill(bit,bit+n,0);
      int ans = 0;

      for(int i=0; i<n; i++){
         ll s = a[i] - sum(a[i]-1) - 1;
         ans = (ans + s * F[n-i-1]) % MOD;
         add(a[i],1);
      }
      cout << ans << endl;
   }
   return 0;
}
