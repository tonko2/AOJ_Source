#include <iostream>
using namespace std;

int main()
{
  int money,a,b,count,c,sum;

  while(cin >> money,money){
    sum = 0;
    count = 0;
  for(int i=1; i<=12; i++){
    cin >> a >> b;
    sum += (a-b);
    if(count == 0 && sum >= money){
      c = i;
      count++;
    }
  }
  if(count == 0)
    cout << "NA" << endl;
  else
    cout << c << endl;
  }
  return 0;
}
