#include <iostream>
using namespace std;

int main(){
  int n;
  char num[11];
  while(cin >> n && n){
    sprintf(num,"%o",n);
    for(int i=0; i<11; i++){
      if(num[i] < '4')continue;
      else if(num[i] == '4') num[i] = '5';
      else if(num[i] > '4') num[i] += 2;
    }
    cout << num << endl;
  }
  return 0;
}
