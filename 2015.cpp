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
#include <cctype>

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int h,w;
   while(cin >> h >> w,h|w){
      map<int,int>m,m2,m3;

      vector<int>H,W;
      for(int i=0; i<h; i++){
         int in;
         cin >> in;
         H.push_back(in);
      }

      for(int i=0; i<w; i++){
         int in;
         cin >> in;
         W.push_back(in);
      }

      for(int i=0; i<h; i++){
         int tmp = H[i];
         for(int j=i+1; j<h; j++){
            tmp += H[j];
            H.push_back(tmp);
         }
      }

      for(int i=0; i<w; i++){
         int tmp = W[i];
         for(int j=i+1; j<w; j++){
            tmp += W[j];
            W.push_back(tmp);
         }
      }
      
      for(int i=0; i<H.size(); i++) m[H[i]]++,m2[H[i]]++;
      for(int i=0; i<W.size(); i++) m[W[i]]++,m3[W[i]]++;
      
      map<int,int>::iterator it = m.begin();

      ll ans = 0;
      while(it != m.end()){
         ans += (m2[it->first] * m3[it->first]);
         it++;
      }
      cout << ans << endl;
      
   }
  return 0;
}
