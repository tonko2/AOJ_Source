#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
  int a,b,n=1,d;
  char c;
  pair<int,int>p;
  map<pair<int,int>,int,greater<pair<int,int> > >m;
  while(cin >> a >> c >> b){
    if(a == 0 && b == 0)break;
    p = pair<int,int>(b,a);
    m[p] = 0;
  }
  
  map<pair<int,int>,int>::iterator it = m.begin();

  d = (*it).first.first;
  
  while(it != m.end()){
    if((*it).first.first == d){
      (*it).second = n;
    }
    else{
      ++n;
      (*it).second = n;
      d = (*it).first.first;
    }
    it++;
  }
  
  while(cin >> a){
    map<pair<int,int>,int>::iterator it = m.begin();
    while(it != m.end()){
      if((*it).first.second == a)
	cout << (*it).second << endl;
      it++;
    }
  }
  return 0;
}
