
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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int a[2001];
int main(){

   for(int i=0; i<=1000; i++)
      for(int j=0; j<=1000; j++) a[i+j]++;
   
   int n;
   while(cin >> n){
      int ans = 0;
      for(int i=0; i<=2000; i++){
         int tmp = n - i;
         if(tmp < 0 || tmp > 2000)continue;
         ans += a[tmp] * a[i];
      }
      cout << ans << endl;
   }
   return 0;
}
