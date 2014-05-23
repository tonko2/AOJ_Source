#include <iostream>
using namespace std;

int main()
{
  int n,b;

  while(cin >> n,n){
    int a[10]={};
    for(int i=0; i<n; i++){
      cin >> b;
      a[b]++;
    }

    for(int i=0; i<10; i++){
      if(a[i]==0)
	cout << '-';
      else{
	for(int j=0; j<a[i]; j++){
	  cout << '*';
	}
      }
      cout << endl;
    }
  }
  return 0;
}
