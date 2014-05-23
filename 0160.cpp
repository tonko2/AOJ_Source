#include <iostream>
using namespace std;

int main()
{
  int n,x,y,h,w,sum,money;

  while(cin >> n){
    if(n == 0)break;
    sum = 0;
    for(int i=0; i<n; i++){
      cin >> x >> y >> h >> w;
      
      if(x+y+h > 160 && w > 25){
	money = 0;
	sum += 0;
      }
      else if(x+y+h <= 60 && w <= 2){
	money = 600;
	sum += money;
      }
      else if(x+y+h <= 80 && w <= 5){
	money = 800;
	sum += money;
      }
      
      else if(x+y+h <= 100 && w <= 10){
	money = 1000;
	sum += money;
      }
      else if(x+y+h <= 120 && w <= 15){
	money = 1200;
	sum += money;
      }
      else if(x+y+h <= 140 && w <= 20){
	money = 1400;
	sum += money;
      }
      else if(x+y+h <= 160 && w <= 25){
	money = 1600;
	sum += money;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
