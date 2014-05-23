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

int main(){
   int n;
   while(cin >> n && n){
      int ans = 0;
      int a = sqrt(n);
      for(int i=0; i<=a; i++){
         for(int j=i; j<=a; j++){
            for(int k=j; k<=a; k++){
               for(int l=k; l<=a; l++){
                  if(i*i+j*j+k*k+l*l == n)ans++;
               }
            }
         }
      }
      cout << ans << endl;
   }
  return 0;
}
