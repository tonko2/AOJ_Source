#include <iostream>
using namespace std;

int main()
{
  int n,x,y,z,sum;
  
  while(cin >> n,n){
    sum = 0;
    z = 0;

    if(n >= 8){
      for(z=2; sum<n; z++)
	sum += (z*z*z);
    }

    for(y=0; ; y++){
      sum += (y*y);
      if(sum >= n)break;
    }

    if(sum > n){
      y -= 1;
    sum -= y*y;
    }

    for(x=0; ; x++){
      sum += x;
      if(sum == n)break;
    }

    cout << x+y+z << endl;
    cout <<"x=" << x << "y=" << y << "z=" << z << endl;
  }
  return 0;
}
