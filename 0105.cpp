#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
  string s;
  int n,cn;
  map<string,set<int> >m;

  while(cin >> s >> n){
    m[s].insert(n);
  }

  map<string,set<int> >::iterator it_map = m.begin();

  while(it_map != m.end()){
    cn = 0;
    cout << (*it_map).first << endl;
    set<int>::iterator it_set = m[(*it_map).first].begin();
    
    while(it_set != m[(*it_map).first].end()){
      if(cn)
	cout << ' ';
      cout <<  (*it_set);
      cn = 1;
      it_set++;
    }
    cout << endl;
    it_map++;
  }
  return 0;
}
