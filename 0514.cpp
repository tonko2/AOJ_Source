#include <iostream>
using namespace std;

int main(){
  int a,b,c,n,data[1001];
  int i[1001],j[1001],k[1001],comp[1001];
  while(cin >> a >> b >> c,a||b||c){
    fill(data,data+1001,2);
    
    cin >> n;
    
    for(int l=0; l<n; l++){
      cin >> i[l] >> j[l] >> k[l] >> comp[l];
      if(comp[l])data[i[l]] = data[j[l]] = data[k[l]] = 1;
    }
    
    for(int l=0; l<n; l++){
      if(!comp[l]){
	if(data[i[l]] == 1 && data[j[l]] == 1) data[k[l]] = 0;
	else if(data[i[l]] == 1 && data[k[l]] == 1) data[j[l]] = 0;
	else if(data[j[l]] == 1 && data[k[l]] == 1) data[i[l]] = 0;
      }
    }
    
    for(int l=1; l<=a+b+c; l++)
      cout << data[l] << endl;
  }
  return 0;
}
