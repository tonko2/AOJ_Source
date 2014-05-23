#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const char c[] = {'R','D','L','U'};

int main(){
   bool wall[4][10][10];
   string s;
   memset(wall,false,sizeof(wall));
   for(int i=0; i<9; i++){
      cin >> s;
      if(i % 2){
         for(int j=0; j<5; j++){
            if(s[j] == '1')
               wall[1][i/2][j] = wall[3][i/2+1][j] = true;
         }
      } else {
         for(int j=0; j<4; j++){
            if(s[j] == '1')
               wall[0][i/2][j] = wall[2][i/2][j+1] = true;
         }
      }
   }

   int x = 0, y = 0, d = 0;
   bool flag = false;
   while(true){
      cout << c[d];
      x += dx[d];
      y += dy[d];
      
      if(wall[(d+3)%4][y][x]) d = (d+3) % 4;
      else if(!wall[d][y][x]){
         if(wall[(d+1)%4][y][x]) d = (d+1) % 4;
         else d = (d+2) % 4;
      }
      if(x == 0 && y == 0)break;
   }
   cout << endl;

   
   return 0;
}
