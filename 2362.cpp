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
  string s,ans;
  while(cin >> s){
    vector<string>v;
    for(int i=0; i<s.size(); i++){
      if(s[i] == 'e'){
	v.push_back("egg");
	i += 2;
      }
      else{
	v.push_back("chicken");
	i += 6;
      }
    }

    ans = v[0];
    int cnt = 0;
    vector<pair<int,string> >v2;

    for(int i=0; i<v.size()-1; i++){
      if(v[i] != v[i+1]){
	ans = v[i+1];
	cnt++;
      }
      else if(v[i] == v[i+1]){
	v2.push_back(make_pair(cnt,ans));
	cnt = 0;
	ans = v[i+1];
      }
    }

    v2.push_back(make_pair(cnt,ans));

    int Max = 0;
    for(int i=0; i<v2.size(); i++){
      Max = max(Max,v2[i].first);
    }

    for(int i=0; i<v2.size(); i++){
      if(v2[i].first == Max){
	ans = v2[i].second;
	break;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
