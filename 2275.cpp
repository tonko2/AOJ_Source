#include <iostream>
using namespace std;

long long a,b,counting;
int main(){

  cin >> a >> b;
  for(int i=a-b; i<=a+b; i++)
    if(i % 2 == 0 && i % 3 == 0)counting++; 

  cout << (a+b)-(a-b)+1-counting << endl;
  return 0;
}
