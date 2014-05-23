#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  string s,max="";

  map<string,int>p;
  map<int,string>p2;

  while(cin >> s){
    if(s.size() > max.size())
      max = s;
    p[s]++;
  }

  map<string,int>::iterator it = p.begin();
  while(it != p.end()){
    p2.insert(map<int,string>::value_type((*it).second,(*it).first));
    it++;
  }

  cout << (*p2.rbegin()).second << ' ' << max << endl;
}
