#include <iostream>
using namespace std;

const int MAX = 50;
int main(){
  int n,p,P,ans,data[MAX];

  while(cin >> n >> p,(n|p)){
    fill(data,data+MAX,0);
    int P = p,ans;

    while(1){
      for(int i=0; i<n; i++){
	if(P){
	  if(++data[i] == p){
	    ans = i;
	    goto end;
	  }
	  P--;
	}
	else{
	  P += data[i];
	  data[i] = 0;
	}
      }
    }
  end:;
    cout << ans << endl;
  }
  return 0;
}
