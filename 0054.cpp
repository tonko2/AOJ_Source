#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  while(cin >> a >> b >> c){
    int sum = 0;

    if(a / b){
      a %= b;
    }

    for(int i=0; i<c; i++){
      sum += (a*10) / b;
      a = a*10 % b;
    }
    cout << sum << endl;
  }
  return 0;
}
