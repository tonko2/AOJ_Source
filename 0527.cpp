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
   int n;
   while(cin >> n && n){
      vector<int>now_black,now_white;
      int wcnt = 0, bcnt = 0;
      for(int i=1; i<=n; i++){
         int in;
         cin >> in;
         if(i % 2 == 0){
            if(in){
               bcnt++;
               if(now_black.size() == 0 || now_black.back() == 0){
                  bcnt = i;
                  wcnt = 0;
                  while(now_white.size()) now_white.pop_back();
                  now_black.push_back(i);
               } else if(now_black.back() == i-1){
                  now_black.push_back(i);
               } else {
                  bcnt += i-now_black.back() - 1;
                  wcnt -= i-now_black.back() - 1;
                  while(true){
                     if(now_black.back() < now_white.back()){
                        now_white.pop_back();
                     } else break;
                  }
                  now_black.push_back(i);
               }
            }
            
            else {
               wcnt++;
               if(now_white.size() == 0 || now_white.back() == 0){
                  bcnt = 0;
                  wcnt = i;
                  while(now_black.size()) now_black.pop_back();
                  now_white.push_back(i);
               } else if(now_white.back() == i-1){
                  now_white.push_back(i);
               } else {
                  wcnt += i-now_white.back() - 1;
                  bcnt -= i-now_white.back() - 1;
                  while(true){
                     if(now_white.back() < now_black.back()){
                        now_black.pop_back();
                     } else break;
                  }
                  now_white.push_back(i);
               }
            }
         } else {
            if(in) bcnt++,now_black.push_back(i);
            else wcnt++,now_white.push_back(i);
         }
      }
      cout << wcnt << endl;
   }
   return 0;
}
