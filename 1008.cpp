#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<int,int> p;
  int a,n;
  while(cin >> n,n){
    p.clear();
    for(int i=0;i<n;i++){
      cin >> a;
      p[a]++;
    }
    map<int,int>::iterator it = p.begin();
    while(it != p.end()){
      if((*it).second > n/2){
	cout << (*it).first << endl;
	break;
      }
      it++;
      if(it == p.end())
	cout << "NO COLOR" << endl;
    }
  }
}
