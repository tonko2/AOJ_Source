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
  int n,m,goal,d;
  char s[200];
  while(cin >> n && n){
    int ans = 1,now;
    pair<int,int>ans2;
    vector<vector<char> >v(50,vector<char>(50));    
    vector<vector<char> >dummy(50,vector<char>(50));
    cin >> m >> goal >> d;
    for(int i=0; i<d; i++){
      cin >> s;
      for(int j=0; j<n-1; j++) dummy[i][j] = s[j];
      dummy[i][n-1] = '0';
    }
    now = m;
    for(int i=0; i<d; i++){
      for(int j=0; j<n-1; j++){
	if(dummy[i][j] == '1'){
	  if(j+1 == now){
	    now = j+2;;
	    break;
	  }
	  else if(j+2 == now){
	    now = j+1;
	    break;
	  }
	}
      }
    }
    if(now == goal){
      ans = 0;
      goto end;
    }

    v = dummy;
    now = m;
    for(int i=0; i<d; i++){
      for(int j=1; j<n; j++){
	if(j == 1 && dummy[i][j-1] == '0' && dummy[i][j] == '0'){
	  v[i][j-1] = '1';
	  ans2.first = i+1;
	  ans2.second = j;
	  goto en;
	}
	if(dummy[i][j-2] == '0' && dummy[i][j] == '0'){
	  v[i][j-1] = '1';
	  ans2.first = i+1;
	  ans2.second = j;
	en:;
	  for(int k=0; k<d; k++){
	    for(int l=0; l<n-1; l++){
	      if(v[k][l] == '1'){
		if(l+1 == now){
		  now = l+2;;
		  break;
		}
		else if(l+2 == now){
		  now = l+1;
		  break;
		}
	      }
	    }
	  }
	  if(now == goal){
	    ans = -1;
	    goto end;
	}
	  now = m;
	  v = dummy;
	}
      }
    }
  end:;
    if(ans == 1) cout << ans << endl;
    else if(ans == 0) cout << ans << endl;
    else cout << ans2.first << ' ' << ans2.second << endl;
  }
  return 0;
}
