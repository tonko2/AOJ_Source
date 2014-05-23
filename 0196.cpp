#include <iostream>
#include <map>
using namespace std;

int main(){
  int n;
  while(cin >> n && n){
    map<pair<int,pair<int,int> >,char,greater<pair<int,pair<int,int> > > > m;
    map<pair<int,pair<int,int> >,char,greater<pair<int,pair<int,int> > > >:: iterator it;
    char t;
    int in,a,b;
    pair<int,pair<int,int> >p;
    pair<int,int>p2;
    for(int i=0; i<n; i++){
      cin >> t;
      a = b = 0;
      for(int j=0; j<n-1; j++){
	cin >> in;
	if(in == 0) a++;
	else if(in == 1)b++;
      }
      p2 = pair<int,int>(a-b,n-i);
      p = pair<int,pair<int,int> >(a,p2);
      m[p] = t;
    }

    for(it = m.begin(); it != m.end(); it++){
      cout << it->second << endl;
    }
  }
  return 0;
}
