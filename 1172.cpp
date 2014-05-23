#include <iostream>
#include <cmath>
#define N 1000000
using namespace std;

int main()
{
  bool p[N+1];
  int n,ans;

  for(int i=0; i<=N; i++)
    p[i] = (i<=1)?false:true;

  for(int i=2; i<=sqrt(N); i++){
    if(p[i]){
      for(int j=2*i; j<=N; j+=i){
	p[j] = false;
      }
    }
  }
  
  while(cin >> n){
    if(n == 0)break;
    ans = 0;
    for(int i=n+1; i<=2*n; i++){
      if(p[i])
	ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
