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
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int n;
   cin >> n;
   while(n--){
      int m,n;
      cin >> m >> n;
      if(m*m + n*n <= 1) {cout << "C" << endl; continue;}
            

      
      for(int x=0; x<=200; x++){
         for(int y=0; y<=200; y++){
            if(m*m+n*n <= 0 || m*m+n*n >= 20000)continue;
            int p = m*x-n*y;
            int q = m*y+n*x;
            if((m*m+n*n) * (x*x+y*y) == (p*p+q*q)){
               if((m*p+n*q) % (m*m+n*n) == 0 && (m*q-n*p) % (m*m+n*n) == 0){
                  cout << "p = " << p << " q = " << q << endl;
               }
            }
         }
      }
   }
  return 0;
}
