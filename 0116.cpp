#include <iostream>
using namespace std;

const int INF = 1 << 30;
int H,W,field[501][501],ans;

void solve(){
  
   for(int i=0; i<H; i++){
      for(int j=1; j<W; j++){
         if(field[i][j] > 0){
            field[i][j] = field[i][j-1]+1;
         } else field[i][j] = 0;
      }
   }

 
   for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
         int k = i, cnt = 1, MIN_H = INF;
         while(field[k][j] && k != H){
            MIN_H = min(MIN_H,field[k][j]);
            ans = max(ans,MIN_H * cnt);
            cnt++,k++;
         }
      }
   }

   
}
int main(){
   char c;
   while(cin >> H >> W,H|W){
      ans = 0;
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            cin >> c;
            if(c == '.') field[i][j] = 1;
             else field[i][j] = 0;
         }
      }
      solve();
      cout << ans << endl;
   }
   return 0;
}
