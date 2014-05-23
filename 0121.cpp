#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
 
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
class State{
public:
   int field[2][4],cost,x,y;
   bool operator < (const State &s) const {
      for(int i=0; i<2; i++){
         for(int j=0; j<4; j++){
            if(field[i][j] != s.field[i][j]) return field[i][j] < s.field[i][j];
         }
      }
      return false;
   }
};
 
int main(){
   set<State>ans;
   State init,input;
   for(int i=0; i<8; i++) init.field[i/4][i%4] = i;
   init.x = init.y = init.cost = 0;
   ans.insert(init);
   queue<State>que;
   que.push(init);
    
   while(!que.empty()){
      init = que.front(), que.pop();
      for(int i=0; i<4; i++){
         State ts = init;
         ts.x += dx[i];
         ts.y += dy[i];
         ts.cost++;
          
         if(ts.x >= 0 && 4 > ts.x && ts.y >= 0 && 2 > ts.y){
            swap(ts.field[ts.y][ts.x],ts.field[init.y][init.x]);
            if(ans.find(ts) != ans.end()) continue;
            ans.insert(ts);
            que.push(ts);
         }
      }
   }
   while(cin >> input.field[0][0]){
      for(int i=1; i<8; i++) cin >> input.field[i/4][i%4];
      cout << ans.find(input)->cost << endl;
   }
   return 0;
}
