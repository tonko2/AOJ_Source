#include <iostream>
#include <cmath>
#define N 1000000
using namespace std;

int main()
{
  int i,j,n;
  bool a[N+1];

  for(i=0; i<=N; i++)
    a[i] = (i<=1)?false:true;

  for(i=2; i<=sqrt(N); i++){
    if(a[i] == true){
      for(j=2*i; j<=N; j+=i){
	a[j] = false;
      }
    }
  }

  while(cin >> n,n){

    int count = 0;
    int sum = 0;
    for(i=2; count != n; i++){
      if(a[i] == true){
	sum += i;
	count++;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
