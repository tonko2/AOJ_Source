#include <iostream>
using namespace std;

const char seg[10][8] = {"0111111","0000110","1011011","1001111","1100110",
			 "1101101","1111101","0100111","1111111","1101111"};
char seg2[0][8];
int main(){
  int n,num;

  while(cin >> n){
    for(int i=0; i<7; i++)
      seg2[0][i] = '0';
    if(n == -1)break;

    for(int i=0; i<n; i++){
      cin >> num;
      
	for(int i=0; i<7; i++){
	  if(seg2[0][i] == seg[num][i]){
	    cout << '0';
	    seg2[0][i] = seg[num][i];
	  }
	  else if(seg2[0][i] != seg[num][i]){
	    cout << '1';
	    seg2[0][i] = seg[num][i];
	  }
	}
	cout << endl;
      }
  }
  return 0;
}
      
