#include <iostream>
#include <cmath>
#define N 500001
using namespace std;

int main()
{
  bool p[N+1];
  int i,j,n;

  for(i=0; i<=N; i++)
    p[i] = (i<=1)?false:true;
  
  for(i=2; i<=sqrt(N); i++){
    if(p[i]){
      for(j=2*i; j<=N; j+=i){
	p[j] = false;
      }
    }
  }
  
  while(cin >> n){
    for(i=n-1; i>=2; i--){
      if(p[i] == 1){
	cout << i << ' ';
	break;
      }
    }
    for(i=n+1; i<=N; i++){
      if(p[i] == 1){
	cout << i << endl;
	break;
      }
    }

  }
  return 0;
}
