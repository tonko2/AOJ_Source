#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <cctype>
#include <math.h>

#define mp make_pair

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int n;
int a[101],b[101];
int memo[101][101];
int getMin(int l, int r){

   if(memo[l][r] != -1) return memo[l][r];

   if(l == r) return 0;
   int ans = 1<<29;
   for(int i=l; i<r; i++){
      ans = min(ans,getMin(l,i) + getMin(i+1,r) + a[l]*b[i]*a[i+1]*b[r]);
   }
   
   return memo[l][r] = ans;
}
int main(){
   while(cin >> n){
      for(int i=0; i<n; i++){
         cin >> a[i] >> b[i];
      }

      memset(memo,-1,sizeof(memo));
      cout << getMin(0,n-1) << endl;
   }
  return 0;
}
