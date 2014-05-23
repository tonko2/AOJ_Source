#include <iostream>
#include <vector>
#include <set>
using namespace std;

int a[20];
bool used[20];
long long ans;
set<int>s;

bool check(){
   
   int value = (a[0]+a[1]+a[2])%a[9];

   if((value == (a[3]+a[4]+a[5])%a[9]) &&
      (value == (a[6]+a[7]+a[8])%a[9]) &&
      (value == (a[0]+a[3]+a[6])%a[9]) &&
      (value == (a[1]+a[4]+a[7])%a[9]) &&
      (value == (a[2]+a[5]+a[8])%a[9]) &&
      (value == (a[0]+a[4]+a[8])%a[9]) &&
      (value == (a[2]+a[4]+a[6])%a[9])) return true;
   
   return false;

   
}

void dfs(int n, int id){
   if(n == 10 && check()){ans++; return;}
   if(id > 9)return;
   if(a[id]) {dfs(n,id+1); return;}
   
      for(int i=1; i<=10; i++){
         if(used[i-1])continue;
         a[id] = i;
         used[i-1] = true;
         dfs(n+1,id+1);
         used[i-1] = false;
         a[id] = 0;
      }
}

int main(){
   while(true){
      ans = 0;
      s.clear();
      fill(used,used+20,false);
      for(int i=0; i<10; i++) cin >> a[i];
      if(a[0] == -1)break;

      int cnt = 0;
      for(int i=0; i<10; i++){
         if(a[i] == 0)continue;
         used[a[i]-1] = true;
         cnt++;
         s.insert(a[i]);
      }
      dfs(cnt,0);
      cout << ans << endl;
   }
   return 0;
}
