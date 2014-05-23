#include <iostream>
#include <string.h>
using namespace std;

const int calc[5] = {10000,1000,100,10,1};
int cnt[5],cnt2;
int main(){
  int n;
  while(cin >> n){
    if(cnt2) cout << endl;
    fill(cnt,cnt+5,0);

      for(int i=0; i<5; i++){
	int a = n / calc[i];
	n -= a * calc[i];
	cnt[i] = a;
      }
      const char abacus[8][6]={"*****",
			       "*****",
			       "=====",
			       "*****",
			       "*****",
			       "*****",
			       "*****",
			       "*****"};
      char ans[8][6];
      for(int i=0; i<8; i++)
	for(int j=0; j<6; j++)
	  ans[i][j] = abacus[i][j];
      for(int i=0; i<5; i++){
	if(cnt[i] >= 5){
	  ans[0][i] = ' ';
	  cnt[i]-=5;
	}
	else ans[1][i] = ' ';

	ans[3+cnt[i]][i] = ' ';
      }

      for(int i=0; i<8; i++)
	cout << ans[i] << endl;
      cnt2 = 1;
  }
  return 0;
}
