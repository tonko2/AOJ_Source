#include <iostream>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

bool array[101][101];
int main(){
   int n,in;
   cin >> n;
   while(n--){
      fill(array[0],array[101],false);
      cin >> in;
      int nowx = 0, nowy = in-1;
      int cnt = 1,dir = 0;
      array[in-1][0] = true;
      while(cnt != in+1){
         int C = 1;
         while(C != in){
            nowx += dx[dir];
            nowy += dy[dir];
            if(!array[nowy][nowx]) array[nowy][nowx] = true;
            else {
               nowx -= dx[dir];
               nowy -= dy[dir];
               array[nowy][nowx] = false;
               C = in-1;
               nowx -= dx[dir];
               nowy -= dy[dir];
            }
            C++;
         }
         dir = (dir+1) % 4;
         cnt++;
      }

      for(int i=0; i<in; i++){
         for(int j=0; j<in; j++){
            if(array[i][j]) cout << '#';
            else cout << ' ';
         }
         cout << endl;
      }
      if(n != 0) cout << endl;
   }
   return 0;
}
