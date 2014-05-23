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
   
   //����ž����
   Dice rotate_front(){return Dice(s,b,e,t,w,n);}
   //����ž����
   Dice rotate_left(){return Dice(e,s,b,n,t,w);}
   //����ž����
   Dice rotate_right(){return Dice(w,s,t,n,b,e);}
   //����ž����
   Dice rotate_back(){return Dice(n,t,e,b,w,s);}
   //���׼����ư����
   Dice move_cw(){return Dice(t,e,n,w,s,b);}
   //ȿ���׼����ư����
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

//��������Ĥ��Ȥ߹�碌(�����front��south)�ˤ�ä�Dice��������
Dice getDice(int top, int south){
   for(int i=0; i<24; i++){
      if(all[i].t == top && all[i].s == south){
         return all[i];
      }
   }
}


//�����ǣ�������ξ��֤���¸
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
