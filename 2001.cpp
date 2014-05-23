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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_M = 1001;
const int MAX_N = 101;
int main(){
   int n,m,a;
   while(cin >> n >> m >> a,n|m|a){
      vector<pair<int,int> >v[MAX_M];
      
      for(int i=0; i<m; i++){
         int h,p,q;
         cin >> h >> p >> q;
         v[h].push_back(make_pair(p,q));
      }
      int now_h = 1000;
      while(1){
         if(now_h == 0) break;
         for(int i=0; i<v[now_h].size(); i++){
            if(v[now_h][i].first == a){
               a = v[now_h][i].second;
               break;
            }
            else if(v[now_h][i].second == a){
               a = v[now_h][i].first;
               break;
            }
         }
         now_h--;
      }
      cout << a << endl;
   }
  return 0;
}
