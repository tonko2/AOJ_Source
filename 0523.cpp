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
#include <stack>
#include <sstream>
#include <climits>
using namespace std;

typedef long long int lli;

int main(){
  int n,in,now;
  while(cin >> n && n){
    deque<int>a,b;
    bool used[201];
    memset(used,0,sizeof(used));
    for(int i=0; i<n; i++){
      cin >> in;
      used[in] = 1;
      a.push_back(in);
    }
    sort(a.begin(),a.end());
    for(int i=1; i<=2*n; i++){
      if(used[i])continue;
      b.push_back(i);
    }
    sort(b.begin(),b.end());

    now = a.front();
    a.pop_front();
    bool flag = true,flag2 = false;
    while(a.size() != 0 && b.size() != 0){
      if(!flag){
	flag = true;
	for(int i=0; i<a.size(); i++){
	  if(a[i] > now && flag2){
	    now = a[i];
	    a.erase(a.begin()+i);
	    //	    cout << "now1 = " << now << endl;
	    flag2 = false;
	    goto end;
	  }
	}
	if(!flag2){
	  now = a[0];
	  a.pop_front();
	  flag2 = false;
	}
      }

      else if(flag){
	  flag = false;
	  for(int i=0; i<b.size(); i++){
      //  cout << "i = " << i << "b = " << b[i] << "now = " << now << endl;
	    if(b[i] > now && !flag2){
	      now = b[i];
	      b.erase(b.begin()+i);
	      flag2 = true;
	      //	      cout << "now2 = " << now << endl;
	      goto end;
	    }
	  }
	  if(flag2){
	  now = b[0];
	  b.pop_front();
	  }
      }
    end:;
    }

    cout << b.size() << endl;
    cout << a.size() << endl;  
  }
  return 0;
}
