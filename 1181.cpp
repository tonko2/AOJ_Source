#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

bool ok[] = {false,false,false,false,true,true,true};

int ht[300][300];
int id[300][300];


class Dice{
public:
   int t,s,e,n,w,b; //t=top,s=south,e=east,n=north,w=west,b=bottom
   Dice(){}
   Dice(int _t, int _s, int _e, int _n, int _w, int _b){
       t = _t;
       s = _s;
       e = _e;
       n = _n;
       w = _w;
       b = _b;
   }
   //前に転がす
   Dice rotate_front(){
      return Dice(s,b,e,t,w,n);
   }
   //左に転がす
   Dice rotate_left(){
      return Dice(e,s,b,n,t,w);
   }
   //右に転がす
   Dice rotate_right(){
      return Dice(w,s,t,n,b,e);
   }
   //後ろに転がす
   Dice rotate_back(){
      return Dice(n,t,e,b,w,s);
   }
   //時計周りに動かす
   Dice move_right(){
      return Dice(t,e,n,w,s,b);
   }
   //反時計周りに動かす
   Dice move_left(){
      return Dice(t,w,s,e,n,b);
   }

   void print(){
      cout << "t=" << t << "s=" << s << "e=" << e << "n=" << n
           << "w=" << w << "b=" << b << endl;
   }
};

vector<Dice>all;

//ここで二つの組み合わせ(今回はfrontとsouth)によってDiceが得られる
Dice getDice(int top, int south){
   for(int i=0; i<24; i++){
      if(all[i].t == top && all[i].s == south){
         return all[i];
      }
   }
}


//ここで２４種類の状態を保存
void allState(){
   all.clear();
   Dice dice(1,3,5,4,2,6);
   for(int i=0; i<6; i++){
      for(int j=0; j<4; j++){
         all.push_back(dice);
         dice = dice.move_right();
      }
      if(i < 4) dice = dice.rotate_front();
      if(i == 3) dice = dice.rotate_right();
      if(i == 4) dice = dice.rotate_right().rotate_right();
   }
}

bool fall(int &x, int &y, Dice &dice){
   Dice maxDice = dice;
   int maxX = x;
   int maxY = y;
   int maxID = 0;
   for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(ht[y][x] <= ht[ny][nx])continue;
      if(i == 0 && !ok[dice.n]) continue;
      if(i == 1 && !ok[dice.e]) continue;
      if(i == 2 && !ok[dice.s]) continue;
      if(i == 3 && !ok[dice.w]) continue;      

      Dice tmp;

      if(i == 0) tmp = dice.rotate_front();
      if(i == 1) tmp = dice.rotate_right();
      if(i == 2) tmp = dice.rotate_back();
      if(i == 3) tmp = dice.rotate_left();

      if(maxID < tmp.b){
         maxID = tmp.b;
         maxX = nx;
         maxY = ny;
         maxDice = tmp;
      }
   }

   if(x != maxX || y != maxY){
      x = maxX;
      y = maxY;
      dice = maxDice;
      return true;
   }
   return false;
}



void solve(Dice dice){
   int x = 150;
   int y = 150;

   while(true){
      bool flag = fall(x,y,dice);
      if(!flag) break;
   }

   ht[y][x]++;
   id[y][x] = dice.t;
}

int main(){
   allState();
   int n;
   while(cin >> n && n){
      memset(ht,0,sizeof(ht));
      memset(id,-1,sizeof(id));

      for(int i=0; i<n; i++){
         int top,south;
         cin >> top >> south;
         Dice dice = getDice(top,south);
         solve(dice);
      }

      int cnt[7];
      memset(cnt,0,sizeof(cnt));

      for(int i=0; i<300; i++){
         for(int j=0; j<300; j++){
            if(id[i][j] != -1){
               cnt[id[i][j] - 1]++;
            }
         }
      }

      for(int i=0; i<6; i++){
         if(i != 0) cout << " ";
         cout << cnt[i];
      }
      cout << endl;
   }
   return 0;
}
