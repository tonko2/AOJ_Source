#include <iostream>
using namespace std;

int main()
{
  double a,b;

  while(cin >> a >> b){
    if(a < 35.50 && b < 71.00)
      cout << "AAA" << endl;
    else if(a < 37.50 && b < 77.00)
      cout << "AA" << endl;
    else if(a < 40.00 && b < 83.00)
      cout << "A" << endl;
    else if(a < 43.00 && b < 89.00)
      cout << "B" << endl;
    else if(a < 50.00 && b < 105.00)
      cout << "C" << endl;
    else if(a < 55.00 && b < 116.00)
      cout << "D" << endl;
    else if(a < 70.00 && b < 148.00)
      cout << 'E' << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
