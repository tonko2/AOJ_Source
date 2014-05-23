#include <iostream>
using namespace std;

const int MAX = 50;
int a[MAX];
int main(){
  int n;

  while(cin >> n && n){
    fill(a,a+50,0);
    for(int i=0; i<n; i++)
      cin >> a[i];

  

    for(int i=0; i<n; i++){
      if(a[i] == a[i+1] - 1){
	for(int j=2; j<=n; j++){
	  if(a[i+1]-1 == a[i+j] - j)continue;
	  else{
	    if(i != 0){
	      cout << ' ' << a[i] << '-' << a[i+j-1];
	      i += j-1;
	      break;
	    }
	    else{
	      cout << a[i] << '-' << a[i+j-1];
	      i += j-1;
	      break;
	    }
	  }
	}
      }
      else{
	if(i == 0)
	  cout << a[i];
	else
	  cout << ' ' << a[i];
      }
    }
    cout << endl;
  }
  return 0;
}

