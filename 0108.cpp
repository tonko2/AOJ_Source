#include <iostream>
#include <map>
using namespace std;

const int MAX = 12;
int main(){
  int number[MAX],dummy[MAX];
  int n,count;
  map<int,int>m;
  while(cin >> n && n){
    m.clear();
    count = 0;
    for(int i=0; i<n; i++) cin >> number[i];

    while(1){
    for(int i=0; i<n; i++){
      m[number[i]]++;
    }
    for(int i=0; i<n; i++) dummy[i] = m[number[i]];

    int count2 = 0;
    for(int i=0; i<n; i++){
      if(dummy[i] == number[i])count2++;
      number[i] = dummy[i];
    }

    if(count2 == n) break;
    m.clear();
    count++;
    }
    cout << count << endl;
    for(int i=0; i<n; i++){
      if(i == 0)
	cout << number[i];
      else
	cout << ' ' << number[i];
    }
    cout << endl;
  }
  return 0;
}
