#include <iostream>
using namespace std;

int main()
{
  int a,b,c;

  while(cin >> a >> b >> c){
    if(((a == 1989 && b == 1 && c >= 8) || (a == 1989 && b >= 2)) || a > 1989)
      cout << "heisei " << a-1989+1 << ' ' << b << ' ' << c << endl;
    else if((a == 1926 && b == 12 && c >= 25) || a > 1926)
      cout << "showa " << a-1926+1 << ' ' << b << ' ' << c << endl;
    else if(((a == 1912 && b == 7 && c >= 30) || a == 1912 &&
	     b >= 8) || a > 1912)
      cout << "taisho " << a-1912+1 << ' ' <<  b << ' ' <<  c << endl;
    else if(((a == 1868 && b == 9 && c >= 8) || (a == 1868 &&
						 b > 9)) || a > 1868)
      cout << "meiji " << a-1868+1 << ' ' <<  b << ' ' <<  c << endl;
    else
      cout << "pre-meiji" << endl;
  }
  return 0;
}

