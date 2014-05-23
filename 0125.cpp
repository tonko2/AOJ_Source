#include <iostream>
using namespace std;

const int month[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
const int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int day2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
  int y1,m1,d1,y2,m2,d2;

  while(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2){
    if(y1+m1+d1+y2+m2+d2 == -6)break;

    int count = 0;
    bool flag = false;
    bool flag2 = false;

    for(int j=month[m1-1]; ; j++,d1=1){


	if(y1 != y2 && j == 13){
	  j = 1;
	  ++y1;
	  flag = false;
	  flag2 = false;
	}

	if(y1 % 4 == 0 && flag == false){
	  if(y1 % 100 == 0) flag = true;
	  if(y1 % 400 == 0) flag = false;
	  
	  if(!flag) flag2 = true;

	}

	if(!flag2){
	  for(int k=d1; k<=day[j-1]; k++){
	    if(y1 == y2 && j == m2 && k == d2) goto end; 
	    count++;
	  }
	}
	else if(flag2){
	  for(int k=d1; k<=day2[j-1]; k++){
	    if(y1 == y2 && j == m2 && k == d2) goto end; 
	    count++;
	  }
	}
    }
  end:;
    cout << count << endl;
  }
  return 0;
}
