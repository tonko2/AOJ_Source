#include <iostream>
using namespace std;

int main(){
  int count=6;
  char a[12][12];

  for(int i=0; i<12; i++)
    for(int j=0; j<12; j++)
       a[i][j] = 0;

  while(1){
    // if(cin.eof())break;
    for(int i=0; i<8; i++)
      //      cin >> a[i];
      if(!(cin >> a[i]))return 0; 
      for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
	if(a[i][j] - '0' == 1){
	  if(a[i][j+1]-'0'==1 && a[i+1][j]-'0'==1 && a[i+1][j+1]-'0'==1)
	    cout << 'A' << endl;
	  else if(a[i+1][j]-'0'==1 && a[i+2][j]-'0'==1 && a[i+3][j]-'0'==1)
	    cout << 'B' << endl;
	  else if(a[i][j+1]-'0' == 1 && a[i][j+2]-'0'==1 && a[i][j+3]-'0' == 1)
	    cout << 'C' << endl;
	  else if(a[i+1][j-1]-'0'==1 && a[i+1][j]-'0'==1 &&a[i+2][j-1]-'0'==1)
	    cout << 'D' << endl;
	  else if(a[i][j+1]-'0'==1 && a[i+1][j+1]-'0'==1&&a[i+1][j+2]-'0' == 1)
	    cout << 'E' << endl;
	  else if(a[i+1][j]-'0'==1 &&a[i+1][j+1]-'0'==1 &&a[i+2][j+1]-'0' == 1)
	    cout << 'F' << endl;
	  else if(a[i][j+1]-'0' == 1 && a[i+1][j-1]-'0'==1 && a[i+1][j]-'0'== 1)
	    cout << 'G' << endl;
	}
      }
    }
  }
  return 0;
}

       
