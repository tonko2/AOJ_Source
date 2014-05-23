#include <iostream>
#include <cmath>
using namespace std;
#define N 50000

int main()
{
  int n,i,j;
  int count;
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
 
  while(cin >> n && n){
    count = 0;
    
    for(int k=2; k<=n/2; k++)
      if(a[k] && a[n-k])
	count++;
    cout << count << endl;
  }
  return 0;
}
	     
