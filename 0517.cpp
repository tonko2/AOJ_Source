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
  int n,m;
  while(cin >> n >> m && (n|m)){
    vector<int>v;
    int zero = 0;
    for(int i=0; i<m; i++){
       int in;
       cin >> in;
       if(in == 0){
          zero = 1;
          continue;
       }
       v.push_back(in);
    }

    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0; i<v.size()-1; i++){
       int z = zero;
       int cnt = 1;
       int pos = i;
       while(v[pos] == v[pos+1]-1 && pos < v.size()-1){
          cnt++;
          pos++;
       }
       if(z){
          if(pos == v.size()-1 && v[v.size()-1] != n) cnt++;
          if(pos < v.size() -1 && v[pos] == v[pos+1]-2) cnt+=2,pos++,z=0;
          while(v[pos] == v[pos+1]-1 && pos < v.size()-1){
             cnt++;
             pos++;
          }
       }
       
       if(pos != i) i += (pos - i - 1);
       ans = max(ans,cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
