#include <iostream>
using namespace std;
int main()
{
  int i,j,N,M,a[10000],b,count,masu,count2,count3,count4;


  while(cin >> N >> M){
    if(N == 0 && M == 0)break;
    count=0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    
    for(i=0; i<N; i++)
      cin >> a[i];
    
    for(j=0; j<M; j++){
      cin >> b;
	if(count2 == 0){
	  masu = b;
	  count2++;
	}
	else
	  masu += b;
	
	if(a[masu] > 0){
	  masu += a[masu];
	  count++;
	}
	else if(a[masu] < 0){
	  masu += a[masu];
	  count++;
	}
	else
	  count++;

	if(masu >= N-1 && count3 == 0){
	  count4 = count;
	  count3++;
	}
    }
    cout << count4 << endl;
  }
  return 0;
}
