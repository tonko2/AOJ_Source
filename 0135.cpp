#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(){
   int n,h,m;
   string s;
   cin >> n;
   cin.ignore();
   for(int t=0; t<n; t++){
      cin >> s;
      s[2] = ' ';
      stringstream ss(s);
      ss >> h, ss >> m;

      int dis = h * 30 + m / 2.0 - m * 6;
      if(dis < 0) dis *= -1;
      if(dis > 180) dis = 360 - dis;
      if(dis >= 0 && dis < 30) cout << "alert" << endl;
      else if(dis >= 90 && dis <= 180) cout << "safe" << endl;
      else cout << "warning" << endl;
   }
   return 0;
}
