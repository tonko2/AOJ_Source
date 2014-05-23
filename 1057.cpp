#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
const int INF = 1 << 29;
typedef pair<int,int>P;


class Dice{
public:
   int t,s,e,n,w,b; //t=top,s=south,e=east,n=north,w=west,b=bottom
   Dice(){}
   Dice(int t, int s, int e, int n, int w, int b):t(t),s(s),e(e),n(n),w(w),b(b){}
   
   //前に転がす
   Dice rotate_front(){return Dice(s,b,e,t,w,n);}
   //左に転がす
   Dice rotate_left(){return Dice(e,s,b,n,t,w);}
   //右に転がす
   Dice rotate_right(){return Dice(w,s,t,n,b,e);}
   //後ろに転がす
   Dice rotate_back(){return Dice(n,t,e,b,w,s);}
   //時計周りに動かす
   Dice move_cw(){return Dice(t,e,n,w,s,b);}
   //反時計周りに動かす
   Dice move_ccw(){return Dice(t,w,s,e,n,b);}

   void print(){
      cout << "t=" << t << "s=" << s << "e=" << e << "n=" << n
           << "w=" << w << "b=" << b << endl;
   }

   bool operator < (const Dice &s) const{
      return true;
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
   Dice dice(1,2,3,5,4,6);
   for(int i=0; i<6; i++){
      for(int j=0; j<4; j++){
         all.push_back(dice);
         dice = dice.move_cw();
      }
      if(i < 4) dice = dice.rotate_front();
      if(i == 3) dice = dice.rotate_right();
      if(i == 4) dice = dice.rotate_right().rotate_right();
   }
}

const int MAX = 10;
int h,w;
int sx,sy,gx,gy;
int d[MAX][MAX],field[MAX][MAX];


int main(){
   allState();
   while(cin >> h >> w,h|w){
      Dice dice = getDice(1,2);
      
      for(int i=0; i<h; i++)
         for(int j=0; j<w; j++) cin >> field[i][j];

      fill(d[0],d[MAX],INF);
      
      cin >> sy >> sx;
      cin >> gy >> gx;

   }
   return 0;
}
