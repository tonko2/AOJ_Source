#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 15;
int n,sx,sy,ans[MAX][MAX],counting;

void dfs(int x, int y){
  if(counting == n*n)return;
 
 if(x >= 0 && n > x && y >= 0 && n > y && ans[x][y] == 0){
   ans[x][y] = ++counting;
   dfs(x+1,y+1);
 }
 
 if(ans[x][y] != 0){
   if(x == n-1 && y == n-1)
     dfs(0,0);
   else if(x == n-1 && y == 0)
     dfs(0,n-1);
   else
     dfs(x+1,y-1);
 }
 
 if(y >= n && x < n) dfs(x,0);
 
 if(x >= n && y < n) dfs(0,y);
 
 if(x < n && y < 0) dfs(x,n-1);
}

int main(){
  while(scanf("%d",&n) != EOF){
    if(n == 0)break;
    counting = 1;
    for(int i=0; i<MAX; i++)
      for(int j=0; j<MAX; j++)ans[i][j] = 0;

    sx = (n / 2) + 1, sy = n / 2;
    ans[sx][sy] = 1;

    dfs(sx+1,sy+1);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	  printf("%4d",ans[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
