#include <iostream>
using namespace std;

const int total2 = 7200;

int main(){
  int h,m,s,h2,m2,s2,h3,m3,s3,total,total_of_3times;

  while(cin >> h >> m >> s){
    if(h == -1 && m == -1 && s == -1)break;
    total = 3600*h + 60*m + s;
    total = total2 - total;
    total_of_3times = total * 3;
    h2 = total / 3600;
    while(total / 3600){
      total = total % 3600;
    }
    m2 = total / 60;
    s2 = total % 60;

    h3 = total_of_3times / 3600;
    while(total_of_3times / 3600){
      total_of_3times = total_of_3times % 3600;
    }
    m3 = total_of_3times / 60;
    s3 = total_of_3times % 60;
  
    if(h2 >= 10)
      cout << h2 << ':';
    else
      cout << '0' << h2 << ':';
    if(m2 >= 10)
      cout << m2 << ':';
    else
      cout << '0' << m2 << ':';
    if(s2 >= 10)
      cout << s2;
    else
      cout << '0' << s2;  
    cout << endl;

    if(h3 >= 10)
      cout << h3 << ':';
    else
      cout << '0' << h3 << ':';
    if(m3 >= 10)
      cout << m3 << ':';
    else
      cout << '0' << m3 << ':';
    if(s3 >= 10)
      cout << s3;
    else
      cout << '0' << s3;  
    cout << endl;
  }
  return 0;
}
