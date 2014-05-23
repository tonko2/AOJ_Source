#include <iostream>
#include <set>
#include <vector>
using namespace std;

int a[8];
int ans;
char grid[4][4];
int cnt;
typedef pair<int,int> P;

void print(){
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         cout << grid[i][j];
      }
      cout << endl;
   }
}

void dfs(int n){
   if(n == 8){ans++; return;}
//   print();
//   cout << endl;
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         if(grid[i][j] != 'X')continue;
         grid[i][j] = 'A'+n;

         for(int k=0; k<8; k+=2){
            if(j+a[k] < 0 || j+a[k] >= 4 || i+a[k+1] < 0 || i+a[k+1] >= 4)continue;
            if(grid[i+a[k+1]][j+a[k]] != 'X')continue;
            grid[i+a[k+1]][j+a[k]] = 'A' + n;
            dfs(n+1);
            grid[i+a[k+1]][j+a[k]] = 'X';
         }
         
         grid[i][j] = 'X';
         return;
      }
   }
}

int main(){
   while(cin >> a[0]){
      if(a[0] > 4)break;
      for(int i=1; i<8; i++) cin >> a[i];
      ans = 0;
      cnt = 0;
      fill(grid[0],grid[4],'X');
      dfs(0);
      
      cout << ans << endl;
   }
   return 0;
}
