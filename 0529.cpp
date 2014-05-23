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

int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      vector<int>v;
      vector<int>v2;
      for(int i=0; i<n; i++){
         int in;
         cin >> in;
         v.push_back(in);
         v2.push_back(in);
      }
      v.push_back(0);

      int size = v.size();

      for(int i=0; i<size; i++){
         for(int j=0; j<size; j++){
            v2.push_back(v[i]+v[j]);
         }
      }
   
      sort(v2.begin(),v2.end());
      v2.erase(unique(v2.begin(),v2.end()),v2.end());
      int ans = 0;
      for(int i=0; i<v2.size(); i++){
         if(m - v2[i] < 0)continue;
         vector<int>::iterator it = upper_bound(v2.begin(),v2.end(),m-v2[i]);
         it--;
         ans = max(ans,*it + v2[i]);
      }
      cout << ans << endl;
   }
  return 0;
}
