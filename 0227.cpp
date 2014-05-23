#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,m,sum,a;

  while(cin >> n >> m,n,m){
    sum = 0;
    vector<int>v;
    for(int i=0; i<n; i++){
      cin >> a;
      v.push_back(a);
    }

    sort(v.rbegin(),v.rend());

    for(int i=m-1; i<n; i+=m)
      v[i] = 0;

    for(int i=0; i<n; i++)
      sum += v[i];

    cout << sum << endl;

  }
  return 0;
}
