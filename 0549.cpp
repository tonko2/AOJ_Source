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

const int MAX_N = 100000;
int n;
int a[MAX_N+1],bit[MAX_N+1];

int sum(int i){
   int s = 0;
   while(i > 0){
      s += bit[i];
      i -= i&-i;
   }
   return s;
}

void add(int i, int x){
   while(i <= n){
      bit[i] += x;
      i += i&-i;
   }
}

int main(){
   int m;
   cin >> n >> m;

   for(int i=0; i<n-1; i++){
      cin >> a[i];
      add(i+1,a[i]);
   }

   int a2[MAX_N+1];
   for(int i=0; i<m; i++) cin >> a2[i];

   int now = 0;
   int ans = 0;
   for(int i=0; i<m; i++){
      if(a2[i] > 0){
         ans = (ans + sum(now+a2[i]) - sum(now)) % MAX_N;
         now += a2[i];
      } else {
         ans = (ans + sum(now) - sum(now+a2[i])) % MAX_N;
         now += a2[i];
      }
   }
   
   cout << ans << endl;
  return 0;
}
