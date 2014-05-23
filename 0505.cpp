#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int i,n,m,b;

  while(cin >> n >> m,n,m){
    pair<int,int>p[m];
    for(int i=0; i<m; i++){
      p[i].first = 0;
      p[i].second = i+1;
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	cin >> b;
	if(b == 1)
	  p[j].first++;
      }
    }

    for(int i=0; i<m-1; i++){
      for(int j=m-1; j>i; j--){
	if(p[j].first > p[j-1].first)
	  swap(p[j],p[j-1]);
      }
    }

    for(int i=0; i<m; i++){
      if(i != 0)
	cout << ' ';
      cout << p[i].second;
    }
    cout << endl;
  }
  return 0;
}
