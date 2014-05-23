#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

set<ll> getSet(ll n){
   set<ll>s;
   for(int i=1; i*i<=n; i++){
      if(n % i == 0){
         s.insert(i);
         s.insert(n/i);
      }
   }
   return s;
}

int main(int argc, char *argv[])
{
   int n;
   set<ll>s[3];
   cin >> n;
   map<int,int>m;
   for(int i=0; i<n; i++){
      int in;
      cin >> in;
      s[i] = getSet(in);
   }

   for(int i=0; i<n; i++){
      set<ll>::iterator it = s[i].begin();
      while(it != s[i].end()){
         m[*it]++;
         it++;
      }
   }
   
      map<int,int>::iterator it = m.begin();
      while(it != m.end()){
         if(it->second == n) cout << it->first << endl;
         it++;
      }
   return 0;
}
