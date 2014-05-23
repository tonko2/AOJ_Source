#include <iostream>
using namespace std;

int main(){
  int n,total_t = 0,total_h = 0;
  string s1,s2;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> s1 >> s2;
    if(s1 == s2){
      total_t += 1;
      total_h += 1;
    }
    else if(s1 > s2){
      total_t += 3;
    }else{
      total_h += 3;
    }
  }
  cout << total_t << ' ' << total_h << endl;
  return 0;
}
