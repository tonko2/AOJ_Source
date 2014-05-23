#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int cups[3] = {1,0,0};
  char a,b,comma,c;
  while(cin >> a >> comma >> b)
    swap(cups[a - 'A'],cups[b - 'A']);
  c = cups[0]*'A' + cups[1]*'B' + cups[2]*'C';
  cout << c << endl;
  return 0;
}
