#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int w,q,id,W,data[101],f,l;
  char in;
  while(cin >> w >> q && (w|q)){
    memset(data,-1,sizeof(data));
    for(int t=0; t<q; t++){
      int cnt = 0;
      bool flag = false;
      cin >> in;
      if(in == 's'){
	cin >> id >> W;
      for(int i=0; i<w; i++){
	if(data[i] == -1){
	  cnt++;
	}
	else cnt = 0;
	if(cnt == 1) f = i;
	if(cnt == W){
	  cout << f << endl;
	  for(int j=f; j<=i; j++){
	    data[j] = id;
	  }
	  flag = true;
	  break;
	}
      }
      if(!flag) cout << "impossible" << endl;
      }
      else{
	cin >> id;
	for(int i=0; i<w; i++){
	  if(data[i] == id) data[i] = -1;
	}
      }
    }
    cout << "END" << endl;
  }
  return 0;
}
      

