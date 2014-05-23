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

const int MAX = 2000;
int dp[MAX+1][MAX+1];
int data[MAX+1][MAX+1];
int main(){
   string s,s2;
   while(cin >> s){
      s2 = s;
      reverse(s2.begin(),s2.end());
      fill(dp[0],dp[MAX+1],0);
      fill(data[0],data[MAX+1],0);
      
      for(int i=0; i<s.size(); i++){
         for(int j=0; j<s.size(); j++){
            if(s[i] == s2[j]){
               dp[i+1][j+1] = dp[i][j]+1;
               data[i+1][j+1] = 0;
            } else if(dp[i+1][j] < dp[i][j+1]){
               dp[i+1][j+1] = dp[i][j+1];
               data[i+1][j+1] = 1;
            } else {
               dp[i+1][j+1] = dp[i+1][j];
               data[i+1][j+1] = -1;
            }
         }
      }
      string ans;
      for(int i=s.size(), j=s.size(); i>0 && j>0;){
         if(data[i][j] == 1) i--;
         else if(data[i][j] == -1) j--;
         else{
            ans += s[i-1];
            i--,j--;
         }
      }
      cout << ans << endl;
   }
  return 0;
}
