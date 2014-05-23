#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
  int n,m,a[101],b[101];
  while(cin >> n >> m && (n|m)){
    bool flag = false;
    int sum = 0;
    int ans2 = 0;
    pair<int,int>ans;
    //input
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    ans.first = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	int dummy1 = 0;
	int dummy2 = 0;
	swap(a[i],b[j]);
	if(accumulate(a,a+n,dummy1) == accumulate(b,b+m,dummy2)){
	  sum = accumulate(a,a+n,dummy1);
	  if(sum > ans2){
	    ans2 = sum;
	    ans.first = b[j],ans.second = a[i];
	  }
	}
	swap(b[j],a[i]);
      }
    }
    if(!ans.first)
      cout << "-1" << endl;
    else
    cout << ans.first << ' ' << ans.second << endl;
  }
  return 0;
}
