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

struct pos{
   double x,y,z,angle;
};

double dot(pos a, pos b){
   return a.x*b.x + a.y*b.y + a.z*b.z;
}

double norm(pos a){
   return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

double getTheta(pos a, pos b){
   return acos(dot(a,b) / (norm(a) * norm(b)));
}
int main(){
   int n,m;
   while(cin >> n && n){
      pos a[501],b[501];
      for(int i=0; i<n; i++){
         cin >> a[i].x >> a[i].y >> a[i].z;
      }
      cin >> m;
      for(int i=0; i<m; i++) cin >> b[i].x >> b[i].y >> b[i].z >> b[i].angle;

      int ans = 0;
      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(getTheta(a[i],b[j]) - b[j].angle < EPS){ans++;break;}
         }
      }
      cout << ans << endl;  
   }
  return 0;
}
