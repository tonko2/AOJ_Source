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

bool compare(pair<int,int> p1, pair<int,int> p2){
   if(p1.second == p2.second) return p1.first < p2.first;
   return p1.second > p2.second;
}
int main(){
   int n;
   pair<int,int>p[20];
   cin >> n;
   for(int i=0; i<n; i++){
      cin >> p[i].first >> p[i].second;
   }
   sort(p,p+n,compare);
   cout << p[0].first << " " << p[0].second << endl;
  return 0;
}
