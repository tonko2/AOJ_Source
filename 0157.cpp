#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
const int MAX = 200;
int main(){
   vector<P>v;
   int n,m;
   while(cin >> n && n){
      P p;
      for(int i=0; i<n; i++){
         cin >> p.first >> p.second;
         v.push_back(p);
      }
      cin >> m;
      for(int i=0; i<m; i++){
         cin >> p.first >> p.second;
         v.push_back(p);
      }



      
   }
   return 0;
}
