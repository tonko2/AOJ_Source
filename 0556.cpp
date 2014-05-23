#include <iostream>
using namespace std;

int main(){
  int n,k,x,y,width,height;

  cin >> n >> k;

  for(int i=0; i<k; i++){
    cin >> x >> y;

    width = min(x,n-x+1);
    height = min(y,n-y+1);

    if(height > width)
      cout << (width-1)%3+1 << endl;
    else
      cout << (height-1)%3+1 << endl;
  }
  return 0;
}
