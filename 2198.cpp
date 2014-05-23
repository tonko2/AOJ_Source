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
const double EPS = 1e-10;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool compare(pair<string,double> a, pair<string,double> b){
   if(abs(a.second-b.second) < EPS){
      return a.first < b.first;
   }
   return a.second > b.second;
}
int main(){
   string L;
   int n,p,a,b,c,d,e,f,s,m;
   bool flag = false;
   while(cin >> n && n){
      if(flag) cout << "#" << endl;
      flag = true;
      pair<string,double>pp[n];
      for(int i=0; i<n; i++){
         cin >> L >> p >> a >> b >> c >> d >> e >> f >> s >> m;
         double totalTime = a+b+c+d+e;
         double totalValue = f * s;
         for(int j=0; j<m-1; j++){
            totalTime += d + e;
            totalValue += f * s;
         }
         totalValue -= p;
         pp[i].first = L;
         pp[i].second = totalValue / totalTime;
      }
      sort(pp,pp+n,compare);

      for(int i=0; i<n; i++){
         cout << pp[i].first << endl;
      }
   }
   cout << "#" << endl;
  return 0;
}
