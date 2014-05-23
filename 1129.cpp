#include <iostream>
#include <deque>
using namespace std;

int main(){
  deque<int>deq;

  int n,r,p,c;

  while(cin >> n >> r && (n || r)){
    deq.clear();
    for(int i=n; i>=1; i--)
      deq.push_back(i);

    for(int j=0; j<r; j++){
      cin >> p >> c;
      
      for(int i=0; i<c; i++){
	deq.push_front(deq[(p+c-2)]);
	deq.erase(deq.begin()+p+c-1);
      }
     
    }
    cout << deq.front() << endl;
  }
  return 0;
}
