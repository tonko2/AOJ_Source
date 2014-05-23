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
   int n,w;
   while(cin >> n >> w,n|w){
      int a[n];
      int Max = 0;
      for(int i=0; i<n; i++){
         cin >> a[i];
         Max = max(Max,a[i]);
      }
      vector<int>v,v2;
      int nowW = w-1;
      while(Max > nowW){
         v.push_back(nowW);
         nowW += w;
      }
      
      v.push_back(nowW);
      v2.resize(v.size());

      int maxH = 0;
      for(int i=0; i<n; i++){
         int nowW = 0;
         for(int j=0; j<v.size(); j++){
            if(nowW <= a[i] && a[i] <= v[j]){
               v2[j]++;
               maxH = max(maxH,v2[j]);
            }
            nowW = v[j]+1;
         }
      }

      double ans = 0;
      for(int i=0; i<v2.size(); i++){
         double W = v2.size();
         double size = v2[i];
         ans += (size/(double)maxH) * (W-1-i)/(W-1);
      }
      printf("%.6f\n",ans+0.01);
   }
  return 0;
}
