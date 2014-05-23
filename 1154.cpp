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

const int MAX = 300000;
bool flag[MAX];
int main(){
   int n;
   while(cin >> n){
      if(n == 1)break;
      vector<int>v;
      fill(flag,flag+MAX,false);

      for(int i=1; i<=MAX; i++)
         if(i % 7 == 1 || i % 7 == 6) v.push_back(i);

      cout << "come" << endl;
      cout << "size = " << v.size() << endl;
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            if(v[i] * v[j] == n) flag[v[i]] = true;
         }
      }

      for(int i=0; i<v.size(); i++){
         if(flag[v[i]]){
            for(int j=v[i]+v[i]; j<MAX; j+=v[i]){
               flag[v[j]] = false;
            }
         }
      }
      cout << n << ":";
      for(int i=0; i<v.size(); i++){
         if(flag[v[i]])
            cout << " " << v[i];
      }
      cout << endl;
   }
  return 0;
}
