#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

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
   //����ž����
   Dice rotate_front(){
      return Dice(s,b,e,t,w,n);
   }
   //����ž����
   Dice rotate_left(){
      return Dice(e,s,b,n,t,w);
   }
   //����ž����
   Dice rotate_right(){
      return Dice(w,s,t,n,b,e);
   }
   //����ž����
   Dice rotate_back(){
      return Dice(n,t,e,b,w,s);
   }
   //���׼����ư����
   Dice move_right(){
      return Dice(t,e,n,w,s,b);
   }
   //ȿ���׼����ư����
   Dice move_left(){
      return Dice(t,w,s,e,n,b);
   }

   void print(){
      cout << "t=" << t << "s=" << s << "e=" << e << "n=" << n
           << "w=" << w << "b=" << b << endl;
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

int main(){
   allState();
   int n;
   string s;
   while(cin >> n && n){
      int cnt = 1;
      Dice dice = getDice(1,2);
      for(int i=0; i<n; i++){
         cin >> s;
         if(s == "North") dice = dice.rotate_front();
         else if(s == "East") dice = dice.rotate_right();
         else if(s == "West") dice = dice.rotate_left();
         else if(s == "South") dice = dice.rotate_back();
         else if(s == "Right") dice = dice.move_right();
         else if(s == "Left") dice = dice.move_left();
         cnt += dice.t;
      }
      cout << cnt << endl;
   }
   return 0;
}
