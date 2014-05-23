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
   while(cin >> n){

      int a[n][3];
      for(int i=0; i<n; i++){
         for(int j=0; j<3; j++){
            cin >> a[i][j];
         }
      }

      int sum[n];
      fill(sum,sum+n,0);
      for(int i=0; i<3; i++){
         map<int,int>m;
         for(int j=0; j<n; j++){
            if(m.count(a[j][i])) m[a[j][i]] = -1;
            else m[a[j][i]] = j;
         }
         map<int,int>::iterator it = m.begin();
         while(it != m.end()){
            if(it->second == -1){ it++; continue;}
            sum[it->second] += it->first;
            it++;
         }
      }

      for(int i=0; i<n; i++) cout << sum[i] << endl;
   }
  return 0;
}
