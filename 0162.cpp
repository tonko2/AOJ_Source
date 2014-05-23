#include <iostream>
using namespace std;

int main(){
  int a,b,ans;
  //  long long MAX = 60 * 60 * 60 * 60 * 60;

  while(cin >> a && a){
    cin >> b;
    int count = 0;
    for(int i=a; i<=b; i++){
      ans = i;
      while(1){
	if(ans == 1){
	  count++;
	  break;
	}
	  if(ans % 2 == 0){
	    ans /= 2;
	  }
	  else if(ans % 3 == 0){
	    ans /= 3;
	  }
	  else if(ans % 5 == 0){
	    ans /= 5;
	  }
	  else break;
	}
      }
    cout << count << endl;
  }
  return 0;
}
