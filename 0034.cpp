#include <iostream>
//#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int a[11],comp1,comp2,ans;
  int l[11],v1,v2;
  double t,x,sum;
  char c;
  
  while(cin>>l[1]>>c>>l[2]>>c>>l[3]>>c>>l[4]>>c>>l[5]>>c>>l[6]>>c>>
	l[7]>>c>>l[8]>>c>>l[9]>>c>>l[10]>>c>>v1>>c>>v2){ 
    bool flag = false;
    fill(a,a+11,0);
    sum = 0;
    for(int i=1; i<=10; i++){
      for(int j=1; j<=i; j++){
	a[i] += l[j];
      }
    }

    t = (double)a[10] / (v1 + v2);
    x = (double)t * v1;

    for(int i=1; i<=10; i++){
      if(a[i] >= x){
	cout << i << endl;
	break;
      }	
    }
  } 
  return 0;
}
