#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int i,w,a,b,n;
  char comma;

  cin >> w;
  cin >> n;

  vector<int>v(w);

  for(i=0; i<w; i++)
    v[i] = i+1;

  for(i=0; i<n; i++){
    cin >> a >> comma >> b;
    swap(v[a-1],v[b-1]);
  }

  for(i=0; i<w; i++)
    cout << v[i] << endl;

  return 0;
}
    print("<br>");
