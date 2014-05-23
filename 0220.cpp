#include <iostream>
using namespace std;

int main(){
  double x,right;
  int keta_l[8],keta_r[4],left,flag1,flag2,flag3;
  int a[] = {128,64,32,16,8,4,2,1};

  while(cin >> x){
    flag1 = 0,flag2 = 0,flag3 = 0;
    if(x == -1.0)break;
    fill(keta_l,keta_l+8,0),fill(keta_r,keta_r+4,0);
    left = (int)x,right = x - (int)x;

    if(right == 0){
      flag3 = 1;
      flag2 = 2;
    }
    if(left >= 256)flag1 = 1;

    for(int i=0; i<8; i++){
      if(left / a[i]){
	keta_l[i] = 1;
	left %= a[i];
      }
    }
    int count = 0;

    if(flag3 == 0){
      while(count != 4){
	right = right*2;
	if(right > 1){
	  right -= 1;
	  keta_r[count] = 1;
	}
	else if(right == 1){
	  keta_r[count] = 1;
	  flag2 = 2;
	  break;
	}
      else
	keta_r[count] = 0;
	count++;
      }
    }

    if(flag1 == 1 || flag2 == 0)
      cout << "NA" << endl;
    else{
      for(int i=0; i<8; i++)
	cout << keta_l[i];
      cout << '.';
      for(int i=0; i<4; i++)
	cout << keta_r[i];
      cout << endl;
    }
  }
  return 0;
}
