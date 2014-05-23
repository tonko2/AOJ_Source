#include <iostream>
#include <cstdio>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
double field[3][3],G[3][3];
int room[3][3];
int main(){
   int n;
   char s,t,b;
   while(cin >> n && n){
      cin >> s >> t >> b;
      fill(field[0],field[3],0);
      fill(room[0],room[3],0);
      fill(G[0],G[3],0);
      int sx,sy,gx,gy,x,y;
      sy = (s-'A')/3, sx = (s-'A')%3;
      gy = (t-'A')/3, gx = (t-'A')%3;
      y = (b-'A')/3, x = (b-'A')%3;

      room[y][x] = 1;
      field[sy][sx] = 1;

      for(int tc=0; tc<n; tc++){
         fill(G[0],G[3],0);
         for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
               for(int k=0; k<4; k++){
                  int nx = j + dx[k], ny = i + dy[k];
                  if(nx < 0 || nx >= 3) nx = j;
                  if(ny < 0 || ny >= 3) ny = i;
                  if(room[ny][nx]) ny = i, nx = j;
                  G[ny][nx] += field[i][j] / 4;
               }
            }
         }
         for(int i=0; i<3; i++)
            for(int j=0; j<3; j++) field[i][j] = G[i][j];
      }
      
      printf("%.8f\n",field[gy][gx]);      
   }
   return 0;
}
