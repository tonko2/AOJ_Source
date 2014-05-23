#include <iostream>
using namespace std;

const int MAX = 100;
int main(){
  int n,m,price,amount;
  string s,s1;
  while(cin >> n && n){
    pair<string,int>p[MAX];
    for(int i=0; i<n; i++){
      cin >> s >> price;
      p[i].first = s;
      p[i].second = price;
    }
    cin >> m;
    for(int i=0; i<m; i++){
      cin >> s >> amount;
      int price2 = 0;
      for(int j=0; j<amount; j++){
	cin >> s1;
	for(int k=0; k<n; k++){
	  if(p[k].first == s1)
	    price2 += p[k].second;
	}
      }
      for(int j=0; j<n; j++){
	if(p[j].first == s){
	  if(p[j].second > price2){
	    p[j].second = price2;
	  }
	}
      }
    }

    cin >> s;

    for(int i=0; i<n; i++){
      if(p[i].first == s){
	cout << p[i].second << endl;
	break;
      }
    }
  }
  return 0;
}
