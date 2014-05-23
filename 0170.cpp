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
 
int INF = 1<<29;
double w,G;
vector<int>ans,v;
int n,W[11],S[11],data[11],first;
string str[11];
 
void dfs(int food_weight, int num, double sum, double sumw, double g){
 
   if(num == n){
      if(G > g){
         G = g;
         ans = v;
      }
      return;
   }
 
   for(int i=0; i<n; i++){
      if(data[i]) continue;
      if(food_weight < W[i]) continue;
      data[i] = 1;
      v.push_back(i);

      if(num == 0){
         dfs(min(food_weight-W[i],S[i]),
             num+1,sum+W[i]*(num+1),sumw+W[i],(sum+W[i]*(num+1)) / W[i]);
      } else {
         dfs(min(food_weight-W[i],S[i]),
             num+1,sum+W[i]*(num+1),sumw+W[i],(sum+W[i]*(num+1)) / sumw);
      }
      data[i] = 0;
      v.pop_back();
   }  
}
    
int main(){
   while(cin >> n && n){
      ans.clear();
      v.clear();
      G = INF;
      for(int i=0; i<n; i++) cin >> str[i] >> W[i] >> S[i];
      fill(data,data+11,0);
      dfs(INF,0,0,0,0);
 
      for(int i=0; i<(int)ans.size(); i++) cout << str[ans[i]] << endl;
   }
  return 0;
}
