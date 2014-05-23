#include <iostream>

using namespace std;

int main(){
  int a[5],b,c,d,e;

  while(cin >> a[0]){
    if(a[0] == 0)break;
    int count1 = 0,count2 = 0,count3 = 0;
    for(int i=1; i<=4; i++){
      cin >> a[i];
    }
      for(int i=0; i<5; i++){
	if(a[i] == 1)
	  count1++;
	else if(a[i] == 2)
	  count2++;
	else
	  count3++;
      }

      if((count1 != 0 && count2 != 0 && count3 != 0) ||
	 count1 == 0 && count2 == 0 && count3 != 0 ||
	 count1 == 0 && count2 != 0  && count3 == 0 ||
	 count1 != 0 && count2 == 0 && count3 == 0){
	for(int i=0; i<5; i++)
	  cout << '3' << endl;
      }
      else if(count1 == 0){
	for(int i=0; i<5; i++){
	  if(a[i] == 2)
	    cout << '1' << endl;
	  else if(a[i] == 3)
	    cout << '2' << endl;
	}
      }
      else if(count2 == 0){
	for(int i=0; i<5; i++){
	  if(a[i] == 1)
	    cout << '2' << endl;
	  else if(a[i] == 3)
	    cout << '1' << endl;
	}
      }
      else{
	for(int i=0; i<5; i++){
	  if(a[i] == 1)
	    cout << '1' << endl;
	  else if(a[i] == 2)
	    cout << '2' << endl;
	}
      }
  }
  return 0;
}
 
