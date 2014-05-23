#include <iostream>
using namespace std;

int main()
{
  int n,count,a,b,x;

  cin >> n;
  for(int i=0; i<n; i++){
    count = 0;
    a = 0;
    b = 0;
    for(int j=0; j<10; j++){
      cin >> x;
      if(a < x)
	a = x;
      else if(b < x)
	b = x;
      else
	count = 1;
    }
    if(count == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
