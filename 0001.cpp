#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int a;

  vector<int>m;

  for(int i=0; i<10; i++){
    cin >> a;
    m.push_back(a);
  }

  sort(m.begin(),m.end());
  reverse(m.begin(),m.end());

  for(int i=0; i<3; i++)
    cout << m[i] << endl;

  return 0;
}
