#include <iostream>
#include <deque>
using namespace std;

int main(){
  int a,b,c;
  deque<int>deq;
  while(cin >> a >> ba >> c){
    deq.clear();
    int count = 0;
    for(int i=1; i<=10; i++) deq.push_back(i);
    deq.erase(deq.begin()+a),deq.erase(deq.begin()+b);
    
    for(int i=0; i<deq.size(); i++)
      if(a+b+deq[i] <= 20) count++;
    
    if(count >= 4) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
   
