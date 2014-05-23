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


bool func(vector<int> v){
   vector<int>tmp;
   for(int i=0; i<v.size()-1; i++){
      tmp.push_back(v[i+1] - v[i]);
   }

   for(int i=0; i<tmp.size()-1; i++){
      if(tmp[i] != tmp[i+1]) return false;
   }
   
   return true;
}
int main(){
   int n;
   while(cin >> n && n){
      vector<int>v;
      int ans = 0;
      for(int i=0; i<n+1; i++){
         int in;
         cin >> in;
         v.push_back(in);
      }

      for(int i=0; i<n+1; i++){
         vector<int>tmp;
         for(int j=0; j<n+1; j++){
            if(i == j)continue;
            tmp.push_back(v[j]);
         }
         if(func(tmp)){
            ans = v[i];
            break;
         }
      }
      cout << ans << endl;  
   }
   return 0;
}
