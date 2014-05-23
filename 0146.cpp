#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


class State{
public:
   int id,dis,num,value;
   State():id(0),dis(0),num(0),value(0){}
   bool operator < (const State &s) const{
      return value < s.value;
   }
};

const int MAX = 16;
int n;
double ans;
State array[MAX],res[MAX];

void dfs(int weight, int cnt, double time, int d){
   if(time > ans) return;
   if(cnt == n){
      if(ans > time){
         ans = time;
         for(int i=0; i<n; i++){
            res[i] = array[i];
         }
      }
      return;
   }

   for(int i=0; i<n; i++){
      if(array[i].value != 0) continue;
      array[i].value = cnt+1;
      double v = (2000.0 / (70 + weight));
      int length = abs(d - array[i].dis);
      
      dfs(weight+array[i].num*20,cnt+1,time+(double)length/v,array[i].dis);
      array[i].value = 0;
   }
}
int main(){
   while(cin >> n){
      for(int i=0; i<n; i++){
         cin >> array[i].id >> array[i].dis >> array[i].num;
      }
      ans = 1 << 29;
      dfs(0,0,0,0);
      sort(res,res+n);
      for(int i=0; i<n; i++){
         if(i == 0) cout << res[i].id;
         else cout << " " << res[i].id;
      }
      cout << endl;
   }
   return 0;
}
