#include <iostream>
#include <deque>
using namespace std;

int main(){
  string s;
  int size;
  deque<int>deq;
  while(cin >> s){
    int count = 0,count2 = 1;
    deq.clear(); //deqの中身をclear
    for(int i=0; i<s.size(); i++)
      deq.push_back(s[i] - '0');　　

    while(deq.size() != 1){
      int size = deq.size();
      for(int i=0; i<size; i++){
	if(i != size-1)
	  deq.push_back((deq[count]+deq[count2]) % 10);
	deq.erase(deq.begin()); //deqの[0]を消去
      }
    }
    cout << deq[0] << endl;
  }
  return 0;
}
