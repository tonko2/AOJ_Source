#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 33;
bool mx[N][N], my[N][N];
int dx[] = {1,-1,-1,1};
int dy[] = {1,1,-1,-1};
int d,x,y;

int main(){
   int n;
   while(cin >> n){
      if(n < 0)break;
      
      for(int i=0; i<N; i++)
         for(int j=0; j<N; j++) mx[i][j] = my[i][j] = false;

      x = 3, y = 1, d = 0;
      
      for(int i=0; i<n; i++){
         int dx,dy;
         char c;
         cin >> c >> dx >> dy;
         if(c == 'x') mx[dy*4][dx*4] = true;
         if(c == 'y') my[dy*4][dx*4] = true;
      }

      x += dx[d];
      y += dy[d];

      while(true){
         
         if(x < 0 || y < 0 || x >= N || y >= N){
            x -= dx[d];
            y -= dy[d];
            break;
         }
         
         if(x == 3 && y == 1) break;

         if(d == 0){
            if(y >= 2 && my[y-2][x]) d = 1;
            else if(x >= 2 && mx[y][x-2]) d = 3;
         } else if(d == 1){
            if(y >= 2 && my[y-2][x]) d = 0;
            else if(x >= 2 && mx[y][x-2]) d = 2;                    
         } else if(d == 2){
            if(y >= 2 && my[y-2][x]) d = 3;
            else if(x >= 2 && mx[y][x-2]) d = 1;
         } else {
            if(y >= 2 && my[y-2][x]) d = 2;
            else if(x >= 2 && mx[y][x-2]) d = 0;
         }

         x += dx[d];
         y += dy[d];
      }

      cout << x*25 << " " << y*25 << endl;
      
   }
   return 0;
}
