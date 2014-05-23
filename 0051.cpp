#include <iostream>
using namespace std;

int main(){
  string s;
  int n,count,a,value,value2;

  cin >> n;
    for(int i=0; i<n; i++){
      cin >> s;
      count = 0;
      value = 0;
      value2 = 0;
      a = 1;
	for(int j=0; j<=9; j++){	
	  for(int l=7; l>=0; l--){
	    if(j == s[l] - '0'){
	      value += a*j;
	      a *= 10;
	      count++;
	    }
	  }
	  if(count == 8)break;
	}
	a = 1;
	count = 0;
	for(int j=9; j>=0; j--){	
	  for(int l=7; l>=0; l--){
	    if(j == s[l] - '0'){
	      value2 += a*j;
	      a *= 10;
	      count++;
	    }
	  }
	  if(count == 8)break;
	}

	cout << value - value2 << endl;
    }
    return 0;
}
