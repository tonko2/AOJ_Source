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

int calc(vector<int> v){
   int n = v.size();
   int sum = 0;
   for(int i=0; i<v.size(); i++) sum += v[i];
   return sum / n;
}

int main(){
   int X,Y,Z;
   int dice[51];
   pair<int,int> grid[51];
   while(cin >> X >> Y >> Z,X|Y|Z){
      for(int i=0; i<X; i++) cin >> dice[i];
      for(int i=0; i<Z; i++){
         int N,E,A;
         cin >> N >> E >> A;
         grid[N] = make_pair(E,A);
      }

      double ans = 0;
      

      cout << max(0,(int)ans) << endl;
   }
  return 0;
}