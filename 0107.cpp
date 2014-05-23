#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b,c;
  double line;
  while(cin >> a >> b >> c){
    if(a + b + c == 0)break;
    line = min((double)sqrt(a*a + b*b),(double)sqrt(a*a+c*c));
    line = min(line,(double)sqrt(b*b+c*c));
    int n;
    cin >> n;
    int m;
    for(int i=0; i<n; i++){
      cin >> m;
      if(2*m > line)
	cout << "OK" << endl;
      else
	cout << "NA" << endl;
    }
  }
  return 0;
}
