#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  vector<int>v(5);
  for(int i=0; i<5; i++)
    cin >> v[i];

  sort(v.rbegin(),v.rend());
  for(int i=0; i<5; i++)
    cout << v[i] << (i-4?' ':'\n');

  return 0;
}
