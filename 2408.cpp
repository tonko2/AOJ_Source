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
     
bool Count[100];
int main(){
   int n,k,m,bunny,r,p,q;
   while(cin >> n >> k){
      memset(Count,0,sizeof(Count));
      vector<vector<int> >vv(k);
      vector<int>v;
      for(int i=0; i<k; i++){
         cin >> m;
         for(int j=0; j<m; j++){
            cin >> bunny;
            v.push_back(bunny);
         }
         vv.push_back(v);
         v.clear();
      }
      int cnt;
      cin >> r;
      for(int i=0; i<r; i++){
         cin >> p >> q;
         for(int j=0; j<vv.size(); j++){
            cnt = 0;
            for(int k=0; k<vv[j].size(); k++){
               if(vv[j][k] == p) cnt++;
               if(vv[j][k] == q) cnt++;
            }
            if(cnt == 2){
               Count[p] = Count[q] = true;
            }
         }
      }
      int ans = 0;
      for(int i=0; i<=100; i++){
         if(Count[i] == true)ans++;
      }
      cout << ans << endl;
   }
   return 0;
}
