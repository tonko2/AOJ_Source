#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  string s;
  vector<int>pe,ap;
  int n;

  getline(cin,s);
  pe.push_back(0);
  ap.push_back(0);

  while(1){
    n=s.find("peach",pe.back() + 5);
    pe.push_back(n);
    if(s
  }
  while(n=s.find("apple",ap.back() + 5), ~n)
    ap.push_back(n);

  for(int i=1; i<pe.size(); i++)
    s.replace(pe[i],5,"apple");
  for(int i=1; i<ap.size(); i++)
    s.replace(ap[i],5,"peach");
  cout << s << endl;

  return 0;
}
