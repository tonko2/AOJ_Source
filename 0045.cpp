#include <iostream>
using namespace std;

int main()
{
  int m,n; int total = 0, ave = 0, row = 0;
  char comma;
  while(cin >> m >> comma >> n){
    total += m * n;
    ave += n;
    row++;
  }
  cout << total << endl;
  cout << (int)(ave / (double)row + 0.5) << endl;
  return 0;
}
