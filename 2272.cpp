#include <iostream>
using namespace std;

const int MAX = 51;
int main(){
   int H,W;
   int data[MAX][MAX];
   string s[MAX];
   while(cin >> H >> W && H && W){
      cin.ignore();
      for(int i=0; i<H; i++) cin >> s[i];
      for(int i=0; i<H; i++)
         for(int j=0; j<W; j++)
            data[i][j] = s[i][j] - '0';

      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            if(i == 0 && j == 0) continue;
            if(i == 0) data[i][j] += data[i][j-1];
            else if(j == 0) data[i][j] += data[i-1][j];
            else data[i][j] += min(data[i-1][j],data[i][j-1]);
         }
      }
      cout << data[H-1][W-1] << endl;
   }
   return 0;
}
