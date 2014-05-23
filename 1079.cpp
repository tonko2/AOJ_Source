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
const int MAX = 50001;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int r,c,q;
   while(cin >> r >> c >> q,r|c|q){
      int A[MAX],B[MAX],order[MAX];
      for(int i=0; i<q; i++){
         cin >> A[i] >> B[i] >> order[i];
      }

      bool R[MAX],C[MAX];
      fill(R,R+MAX,false);
      fill(C,C+MAX,false);

      ll ans = 0;
      for(int i=q-1; i>=0; i--){
         if(order[i] == 0){
            if(A[i]){
               if(C[B[i]])continue;
               C[B[i]] = true;
               c--;
            } else {
               if(R[B[i]])continue;
               R[B[i]] = true;
               r--;
            }
         } else {
            if(A[i]){
               if(C[B[i]])continue;
               C[B[i]] = true;
               c--;
               ans += r;
            } else {
               if(R[B[i]])continue;
               R[B[i]] = true;
               r--;
               ans += c;
            }
         }
      }
      cout << ans << endl;
   }
  return 0;
}
