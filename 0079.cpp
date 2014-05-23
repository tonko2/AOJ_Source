#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  double x,y;
  pair<double,double>p[20];
  int count = 0;
  char comma;
  while(cin >> x >> comma >> y){
    p[count].first = x,p[count].second = y;
    count++;
  }
  double S = 0;
  for(int i=0; i<count; i++){
    S += (p[i].first-p[i+1].first) * (p[i].second+p[i+1].second);
  }
  cout << fixed << setprecision(6);
  if(S < 0) S *= -1;
  cout << S/2 << endl;
  return 0;
}
