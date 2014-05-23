#include <iostream>
using namespace std;

int a[30];
int pos,n;

void dfs(int sum, int p){
   if(sum == n){
      for(int i=0; i<pos; i++){
         if(i == 0) cout << a[i];
         else cout << " " << a[i];
      }
      cout << endl;
      return;
   }

   for(int i=p; i>=1; i--){
      if(sum + i > n)continue;
      a[pos] = i;
      pos++;
      dfs(sum+i,i);
      pos--;
   }
   return;
}
int main(){
   while(cin >> n && n){
      pos = 0;
      dfs(0,n);
   }
   return 0;
}
