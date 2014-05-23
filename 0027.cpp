#include <iostream>
#include <string>
using namespace std;

int main()
{
  string w[7] = {"Monday","Tuesday","Wednesday",
		    "Thursday","Friday","Saturday","Sunday"};
  int m,d,count,i;
  int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
  
  while(1){
    cin >> m >> d;
    if(m == 0)break;

    switch(m){
    case 1:
      count = 4;
      break;
    case 2:
      count = 7;
      break;
    case 3:
      count = 1;
      break;
    case 4:
      count = 4;
      break;
    case 5:
      count = 6;
      break;
    case 6:
      count = 2;
      break;
    case 7:
      count = 4;
      break;
    case 8:
      count = 7;
      break;
    case 9:
      count = 3;
      break;
    case 10:
      count = 5;
      break;
    case 11:
      count = 1;
      break;
    case 12:
      count = 3;
      break;
    }

      for(i=1; i<=a[m-1]; i++){
	if(i == d)break;
	count++;
	if(count % 8 == 0)
	  count = 1;
      }
      
      switch(count){
      case 1:
	cout << w[0] << endl;
	break;
      case 2:
	cout << w[1] << endl;
	break;
      case 3:
	cout << w[2] << endl;
	break;
      case 4:
	cout << w[3] << endl;
	break;
      case 5:
	cout << w[4] << endl;
	break;
      case 6:
	cout << w[5] << endl;
	break;
      case 7:
	cout << w[6] << endl;
	break;
      }
  }
  return 0;
}
