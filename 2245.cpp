#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
class Cube{
public:
   char field[7][3][3];
   int cnt;
   Cube(){cnt=0;}
   
   void insert(int from, int to){
      for(int i=0; i<3; i++)
         for(int j=0; j<3; j++) field[to][i][j] = field[from][i][j];
   }
   
   void clock90(int num){
      char field2[3][3];
      for(int i=0; i<3; i++)
         for(int j=0; j<3; j++) field2[i][j] = field[num][i][j];
      
      for(int i=0; i<3; i++)
         for(int j=0; j<3; j++) field[num][i][j] = field2[3-j-1][i];
   }
   
   void front(){
      insert(5,6);

      //front->bottom
      insert(0,5);
      //top->front
      insert(4,0);
      //back->top
      for(int i=0; i<2; i++) clock90(2);
      insert(2,4);
      //bottom->back
      for(int i=0; i<2; i++) clock90(6);
      insert(6,2);
      
      clock90(1);
      for(int i=0; i<3; i++) clock90(3);
   }
 
  
   void left(){
      insert(5,6);

      //left->bottom
      clock90(3);
      insert(3,5);

      //top->left
      for(int i=0; i<3; i++) clock90(4);
      insert(4,3);

      //right->top
      clock90(1);
      insert(1,4);

      //bottom->right
      for(int i=0; i<3; i++) clock90(6);
      insert(6,1);
      
      clock90(0);
      for(int i=0; i<3; i++) clock90(2);
   }
 
   void right(){
      for(int i=0; i<3; i++) left();
   }
   
   void back(){
      for(int i=0; i<3; i++) front();
   }
 
};
 
bool check(Cube a){
   bool front = false;
   bool back = false;
 
   for(int i=0; i<3; i++)
      if(a.field[0][2][i] == '*') front = true;
 
   for(int i=0; i<3; i++)
      if(a.field[2][2][i] == '*') back = true;

   return front && back;
 
}
 
 
int bfs(Cube a){
   queue<Cube>que;
   que.push(a);
 
   while(!que.empty()){
      Cube tmp = que.front();
      que.pop();
 
      if(check(tmp)) return tmp.cnt;
      
      for(int i=0; i<4; i++){
         Cube t = tmp;
         if(i == 0) t.front();
         if(i == 1) t.right();
         if(i == 2) t.back();
         if(i == 3) t.left();
         t.cnt++;
         que.push(t);
      }
   }
}

bool input(Cube &c){
   for(int k=0; k<6; k++){
      for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
            cin >> c.field[k][i][j];
            if(c.field[k][i][j] == '#') return false;
         }
      }
   }
   return true;
}

int main(){
   string s;
   int cnt = 0;
   Cube c;

   while(cin >> s){
      if(s == "#")break;
      for(int i=0; i<s.size(); i++)
         c.field[cnt/3][cnt%3][i] = s[i];
      cnt++;
      
      if(cnt == 18){
         cout << bfs(c) << endl;
         cnt = 0;
      }
   }
   return 0;
}
