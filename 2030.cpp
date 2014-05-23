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
typedef pair<P,P>PP;
int main(){
   int a,b;
   while(cin >> a >> b,a|b){
      set<P>sa;
      set<P>sb;
      set<PP>pp;
      for(int i=1; i<=a; i++){
         if(a % i == 0) sa.insert(P(min(i,a/i),max(i,a/i)));
      }

      for(int i=1; i<=b; i++){
         if(b % i == 0) sb.insert(P(min(i,b/i),max(i,b/i)));
      }

      set<P>::iterator it,it2;
      set<PP>::iterator iter;
      int ans = 1<<29;
      for(it=sa.begin(); it != sa.end(); it++){
         for(it2=sb.begin(); it2 != sb.end(); it2++){
            int A,B,C,D;
            A = it->first, B = it->second, C = it2->first, D = it2->second;
            vector<int>v;
            v.push_back(A);
            v.push_back(B);
            v.push_back(C);
            v.push_back(D);
            sort(v.begin(),v.end());
            pp.insert(PP(P(v[0],v[1]),P(v[2],v[3])));
         }
      }
      for(iter=pp.begin(); iter != pp.end(); iter++){
         int A,B,C,D;
         A = iter->first.first, B = iter->first.second;
         C = iter->second.first, D = iter->second.second;
         int sum = (A-B) * (A-B) + (B-C) * (B-C) + (C-D) * (C-D);
         ans = min(ans,sum);
      }
      cout << ans << endl;
   }
  return 0;
}
