#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200001;
vector<int>v;
bool prime[MAX];
void init(){
   fill(prime,prime+MAX,true);
   prime[0] = prime[1] = false;
   for(int i=2; i*i<=MAX; i++){
      for(int j=2*i; j<=MAX; j+=i){
         if(prime[j]) prime[j] = false;
      }
   }

   for(int i=2; i<=MAX; i++)
      if(prime[i]) v.push_back(i);
}

int main(){
   init();

   int N,P;
   while(cin >> N >> P){
      if(N == -1 && P == -1)break;
      vector<int>ans;
      vector<int>::iterator it = upper_bound(v.begin(),v.end(),N);
      vector<int>::iterator it2,it3;

      for(it2 = it; it2 < it+100; it2++)
         for(it3= it2; it3< it+100; it3++)
            ans.push_back(*it2+*it3);
      sort(ans.begin(),ans.end());
      cout << ans[P-1] << endl;
   }
   return 0;
}
