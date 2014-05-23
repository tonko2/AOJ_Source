#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 12;
const int INF = 1<<29;
const double EPS = 1e-8;
double dp[1<<MAX_N][MAX_N];
double d[MAX_N][MAX_N];
int array[MAX_N],cnt,end_point;
double rec(int S, int v){
   if(dp[S][v] >= 0) return dp[S][v];
   if(S == (1<<cnt)-1 && v == 0) return dp[S][v] = 0;
   double res = INF;
   
   for(int u=0; u<cnt; u++){
      if(!(S >> u & 1)){
         res = min(res,rec(S | 1 << u,u) + d[v][u]);
      }
   }
   return dp[S][v] = res;
}

void make_dis(){
   for(int i=0; i<cnt; i++){
      for(int j=0; j<cnt; j++){
         d[i][j] = sqrt((array[i]+array[j]) * (array[i]+array[j])
                        - (array[i]-array[j]) * (array[i]-array[j]));
      }
   }
  
}

int main(){
   double box_length;
   string str;
   while(getline(cin,str)){
      stringstream ss(str);
      ss >> box_length;
      cnt = 0;
      while(!ss.eof()){
         int radius;
         ss >> radius;
         array[cnt++] = radius;
      }
      memset(dp,-1,sizeof(dp));
      make_dis();
      double circle_sum = rec(0,0);
      cout << circle_sum << endl;
      if(box_length >= circle_sum) cout << "OK" << endl;
      else cout << "NA" << endl;
   }
   return 0;
}
