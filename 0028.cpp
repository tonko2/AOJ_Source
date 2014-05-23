#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int count=0,a[101],b[101],n,i,j;

  for(i=1; i<=101; i++){
    a[i] = 0;
    b[i] = 0;
  }

  while(cin >> n){
    a[n] += 1;
    b[n] += 1;
  }

  sort(b,b+101);
  reverse(b,b+101);

  for(i=1; i<=100; i++){
    if(b[0] == a[i]){
      a[i] += 500;
      break;
    }
  }
     cout << i << endl;
     
     for(int i=1; i<=101; i++){
       if(b[0] == b[i]){
	 for(int j=1; j<=101; j++){
	   if(b[i] == a[j])
	     cout << j << endl;
	   a[j] += 500;
	 }
       }
     }
  return 0;
}
  

