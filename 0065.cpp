#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main(){
  map<int,int>m,m2;
  string s;
  int a,b;
  char c;

  m.clear();
  m2.clear();

  while(getline(cin,s),s.size() != 0){
    stringstream ss;
    for(int i=0; i<s.size(); i++)
      if(s[i] == ',')
	s[i] = ' ';
    ss << s;
    ss >> a;
    m[a]++;
    ss.str("");
  }
  while(cin >> a >> c >> b){
    if(m[a] != 0){
      if(m2[a] == 0)
	m2[a] += m[a];
      m2[a]++;
    }
  }

  map<int,int>::iterator it = m2.begin();
  while(it != m2.end()){
    cout << (*it).first << ' ' << (*it).second << endl;
    it++;
  }
  return 0;
}
