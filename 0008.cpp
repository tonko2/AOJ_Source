#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{
  int n;
  vector<int>v(4);
  map<vector<int>,bool>m;
  while(cin >> n){
    m.clear();
    for(v[0] = 0; v[0] < 10; v[0]++)
      for(v[1] = 0; v[1] < 10; v[1]++)
	for(v[2] = 0; v[2] < 10; v[2]++)
	  for(v[3] = 0; v[3] < 10; v[3]++)
	    if(v[0]+v[1]+v[2]+v[3] == n)
	      m.insert(pair<vector<int>,bool>(v,true));
    cout << m.size() << endl;
  }
  return 0;
}
