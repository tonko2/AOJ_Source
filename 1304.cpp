#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int N;
char field[6][6];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int sx,sy;
set<string>s;

class State{
public:
   int x,y,cnt;
   char field[6][6];
   State(int x_, int y_, int cnt_, char f[6][6]){
      x = x_;
      y = y_;
      cnt = cnt_;
      for(int i=0; i<6; i++)
         for(int j=0; j<6; j++) field[i][j] = f[i][j];
   }
   bool operator < (const State& s) const {
      return cnt > s.cnt;
   }
   
};

bool check(char f[6][6]){
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++) if(f[i][j] != '.' && f[i][j] != '@') return false;
   return true;
}

string toStr(char f[6][6]){
   string str = "";
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++) str += f[i][j];
   return str;
}

void change(char f[6][6]){

   char tmp[6][6];
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++) tmp[i][j] = f[i][j];
   
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(tmp[i][j] == '@')continue;
         int cnt = 0, cnt2 = 0;
         for(int k=0; k<8; k++){
            int nx = j + dx[k], ny = i + dy[k];
            if(nx<0 || ny<0 || nx>=N || ny>=N)continue;
            if(tmp[i][j] == '.'){
               if(tmp[ny][nx] != '.')cnt++;
            } else if(tmp[i][j] == '#'){
               if(tmp[ny][nx] != '.')cnt2++;
            }
         }
         if(tmp[i][j] == '.'){
            if(cnt == 3) f[i][j] = '#';
         } else {
            if(cnt2 != 2 && cnt2 != 3) f[i][j] = '.';            
         }

      }
   }
}

void print(char f[6][6]){
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         cout << f[i][j];
      }
      cout << endl;
   }
}

int bfs(int X, int Y){
   priority_queue<State>que;
   que.push(State(X,Y,0,field));
   while(!que.empty()){
      State tmp = que.top();
      que.pop();
//     cout << endl;
//     print(tmp.field);
//     cout << endl;
      if(check(tmp.field)){
//         print(tmp.field);
         return tmp.cnt;
      }
      string str = toStr(tmp.field);
      if(s.count(str))continue;
      s.insert(str);

      int x = tmp.x;
      int y = tmp.y;
      
      for(int i=0; i<8; i++){
         int nx = x + dx[i], ny = y + dy[i];
         State t = tmp;
         if(nx < 0 || ny < 0 || nx >= N || ny >= N || t.field[ny][nx] == '#')continue;
         t.x = nx, t.y = ny;
         t.cnt++;
         
         t.field[ny][nx] = '@';
         t.field[y][x] = '.';
//         print(t.field);
         change(t.field);
//         cout << "change" << endl;
//         print(t.field);
//         return -1;
         que.push(t);
      }
   }
   return -1;
}
int main(){
   while(cin >> N && N){
      s.clear();
      for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
            cin >> field[i][j];
            if(field[i][j] == '@'){sx = j, sy = i;}
         }
      }

      int ans = bfs(sx,sy);
      cout << ans << endl;
      
   }
   return 0;
}
