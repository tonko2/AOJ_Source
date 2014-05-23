#include <iostream>
using namespace std;

const int dx[] = {1,0,-1,0,0};
const int dy[] = {0,1,0,-1,0};
int ans[11][11];
int input[11][11];
int tmp[11][11];

bool check(){
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
         if(tmp[i][j]) return false;
      }
   }
   return true;
}

void solve(int x, int y){
   ans[y][x] = 1;

   for(int i=0; i<5; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 10 || ny >= 10)continue;
      tmp[ny][nx] = 1 - tmp[ny][nx];
   }
}

void func(){
   for(int i=1; i<10; i++){
      for(int j=0; j<10; j++){
         if(tmp[i-1][j] == 1) solve(j,i);
      }
   }
}

void print(){
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
         cout << tmp[i][j] << " ";
      }
      cout << endl;
   }
}

int main(){
   int tc;
   cin >> tc;
   while(tc--){
      for(int i=0; i<10; i++)
         for(int j=0; j<10; j++) cin >> input[i][j];

      for(int i=0; i<(1<<10); i++){
         
         fill(ans[0],ans[11],0);
         
         for(int j=0; j<10; j++)
            for(int k=0; k<10; k++) tmp[j][k] = input[j][k];
         
         for(int j=0; j<10; j++){
            if(i & (1<<j)) solve(j,0);
         }

         func();
         if(check()) break;
      }

      for(int i=0; i<10; i++){
         for(int j=0; j<10; j++){
            if(j == 0) cout << ans[i][j];
            else cout << " " << ans[i][j];
         }
         cout << endl;
      }

      
   }
   return 0;
}
