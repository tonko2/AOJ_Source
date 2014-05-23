#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long int lli;

int main(){
  int b,r,g,c,s,t;
  while(cin >> b >> r >> g >> c >> s >> t,(b||r||g||c||s||t)){
    int sum = 100;
    //ビッグボーナス
    sum += -3*b + b*15 + b*5*13;
    //レギュラー
    sum += -3*r + r*15 + r*3*13;
    //グレープ
    sum += -3*g + 7*g;
    //チェリー
    sum += -3*c + 2*c;

    sum += (t-(5*b+b)-(3*r+r)-g-c-s)*-3;
    cout << sum << endl;
  }

  return 0;
}
