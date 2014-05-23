#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int num[30];
  int n,m;
  vector<int>a,b;
  deque<int>deq;
  cin >> n >> m;
  for(int i=2*n-1; i>=0; i--)
    deq.push_back(i+1);

  for(int i=0; i<m; i++){
    int in;
    cin >> in;
    if(in == 0){
      for(int j=0; j<n; j++){
	a.push_back(deq[j]);
      }
      for(int j=n; j<2*n; j++){
	b.push_back(deq[j]);
      }
      deq.clear();

      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());

      for(int j=0; j<2*n; j++){
	if(j % 2 == 0){
	  deq.push_back(a.back());
	  a.pop_back();
	}
	else{
	  deq.push_back(b.back());
	  b.pop_back();
	}
      }
    }
    else{
      rotate(deq.begin(),deq.begin()+(2*n-in),deq.end());     
    }
  }
  for(int i=2*n-1; i>=0; i--)
    cout << deq[i] << endl;
}
