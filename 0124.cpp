#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long int lli;

int main(){
  int n,cnt = 0;
  while(cin >> n && n){
    if(cnt) cout << endl;
    map<pair<int,int>,string,greater<pair<int,int> > >m;
    string s;
    int a,b,c;
    pair<int,int>p;
    for(int i=0; i<n; i++){
      cin >> s >> a >> b >> c;
      p = pair<int,int>(a*3+c,n-i);
      m[p] = s;
    }
    map<pair<int,int>,string,greater<pair<int,int> > >::iterator it;
    for(it = m.begin(); it != m.end(); it++){
      cout << it->second << ',' << it->first.first << endl;
    }
    cnt = 1;
  }
  return 0;
}
