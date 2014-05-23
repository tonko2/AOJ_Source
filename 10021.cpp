#include <iostream>
#include <map>
using namespace std;

int main(){
  int n;
  string s;
  map<string,int>m;

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> s;
    m[s] = 0;
  }

  map<string,int>::iterator it = m.begin();

  cout << (*it).first << endl;

  return 0;
}
