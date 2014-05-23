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

class Rect{
public:
   int w,d;
   Rect(){};
   Rect(int w_, int d_){w = w_, d = d_;}
   bool operator < (const Rect &a) const {
      return w*d < a.w*a.d;
   }

   int getArea(){
      return w * d;
   }
   
};

int main(){
   int n,w,d;
   while(cin >> n >> w >> d,n|w|d){
      vector<Rect>v;
      v.push_back(Rect(w,d));
      for(int i=0; i<n; i++){
         int p,s;
         cin >> p >> s;
         p--;

         s %= v[p].w + v[p].d;
         if(s < v[p].w){
            v.push_back(Rect(s,v[p].d));
            v.push_back(Rect(v[p].w-s,v[p].d));
         } else {
            s -= v[p].w;
            v.push_back(Rect(v[p].w,s));
            v.push_back(Rect(v[p].w,v[p].d-s));
         }

         vector<Rect>::iterator it = v.begin();
         it += p;
         v.erase(it);
         p = v.size()-1;
         int S = v[p-1].w * v[p-1].d;
         int S2 = v[p].w * v[p].d;
         if(S > S2) swap(v[p],v[p-1]);
      }

      sort(v.begin(),v.end());
      for(int i=0; i<v.size(); i++){
         if(i == 0) cout << v[i].getArea();
         else cout << " " << v[i].getArea();
      }
      cout << endl;
   }
   
  return 0;
}
