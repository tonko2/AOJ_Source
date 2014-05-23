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
   int n,k,m;
   while(cin >> n >> k >> m,n|k|m){
      vector<int>v;
      for(int i=0; i<n; i++){
         v.push_back(i+1);
      }
      m--;

      while(v.size() != 1){
         v.erase(v.begin()+m);
         m = (m+k-1) % v.size();
      }
      cout << v[0] << endl;
  
   }
  return 0;
}
