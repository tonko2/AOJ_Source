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
   int n,a = 0;
   cin >> n;
   for(int i=0; i<n; i++){
      string in;
      int num;
      cin >> in >> num;
      if(in == "(") a += num;
      else a -= num;
      if(a < 0){
         cout << "NO" << endl;
         return 0;
      }
   }
   if(a == 0) cout << "YES" << endl;
   else cout << "NO" << endl;
  return 0;
}
