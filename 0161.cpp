#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  int n,id,s1,s2,s3,s4,m1,m2,m3,m4;
  map<int,int>m;

  while(cin >> n && n){
    m.clear();
    for(int i=0; i<n; i++){
      cin >> id >> m1 >> s1 >> m2 >> s2 >> m3 >> s3 >> m4 >> s4;
      m[m1*60+s1+m2*60+s2+m3*60+s3+m4*60+s4] = id;
    }

    map<int,int>::iterator it = m.begin(),it_end = m.end();

    cout << it->second << endl;
    it++;
    cout << it->second << endl;
    it_end--;
    it_end--;
    cout << it_end->second << endl;
  }
  return 0;
}
