#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);
int main(){
   int inx,iny;
   char comma;
   double x=0,y=0;
   double nowR = PI/2;
   while(cin >> inx >> comma >> iny,(inx|iny)){
      x += inx*cos(nowR),y += inx*sin(nowR);
      nowR += -iny*PI/180.0;
   }
   cout << (int)x << endl;
   cout << (int)y << endl;
   return 0;
}
