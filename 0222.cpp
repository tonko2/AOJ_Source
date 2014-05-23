#include <iostream>
#include <cmath>
#define N 10000000
using namespace std;
int a[N+1];
int main()
{
  int n,i,j;

  for(i=0; i<=N; i++)
    a[i] = (i<=1)?0:1;
  
  for(i=2; i<=sqrt(N); i++){
    if(a[i] == 1){
      for(j=2*i; j<=N; j+=i){
	a[j] = 0;
      }
    }
  }
  
  while(cin >> n,n){
    for(i=n; i>=5; i--)
      if(a[i] == 1 && a[i-2] == 1 && a[i-6] == 1 && a[i-8] == 1)
	break;

    cout << i << endl;
  }
  return 0;
}

