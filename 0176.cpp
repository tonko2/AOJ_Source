#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string s;
char tmp[2];
const char color[8][10] = {"black","blue","lime","aqua",
		    "red","fuchsia","yellow","white"};
int a1,b1,c1;
const int a2[8] = {0,0,0,0,255,255,255,255};
const int b2[8] = {0,0,255,255,0,0,255,255};
const int c2[8] = {0,255,0,255,0,255,0,255};

double d[8],comp[8];

pair<double,int>p[8];
void solve(){
  
  s.copy(tmp,2,1);
  a1 = strtol(tmp,NULL,16);
  s.copy(tmp,2,3);
  b1 = strtol(tmp,NULL,16);
  s.copy(tmp,2,5);
  c1 = strtol(tmp,NULL,16);

  for(int i=0; i<8; i++){
    d[i] = sqrt((a1-a2[i])*(a1-a2[i])*(1.0) + (b1-b2[i])*(b1-b2[i]) + 
	       (c1-c2[i])*(c1-c2[i]));
      p[i] = pair<double,int>(d[i],i);
      comp[i] = d[i];
  }

  sort(comp,comp+8);
  
  for(int i=0; i<8; i++){
    if(p[i].first == comp[0]){
      cout << color[p[i].second] << endl;
    break;
    }
  }
}

int main(){
  while(cin >> s){
    if(s == "0")break;
    solve();
  }
  return 0;
}
