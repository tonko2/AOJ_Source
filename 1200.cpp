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
   vector<int>v;
   for(int i=2; i<=(1<<15); i++){
      if(isPrime(i))v.push_back(i);
   }

   int n;
   while(cin >> n && n){
      int ans = 0;
      int tmp = 0;
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            if(v[i]+v[j] == n) ans++;
            if(v[i]+v[j] == n && v[i] == v[j])tmp++;
         }
      }
      
      cout << (ans-tmp)/2 + tmp << endl;
   }
  return 0;
}
