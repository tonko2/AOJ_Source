#include <iostream>
#include <map>
using namespace std;

string s;
char c[1000][8];
int n,m,money,count3,count2;
//int count;
long long int sum;
map<string,int>M;

void solve(){
  map<string,int>::iterator it = M.begin();
  while(it != M.end()){
    //        count = 0;
    count3 = 0;
    for(int j=0; j<8; j++){
      if((*it).first[j] == '*')
	//	count++;
	count3++;
    }
    //    count = 8 - count;
    count3 = 8 - count3;
    for(int i=0; i<m; i++){
      count2 = 0;
      for(int j=0; j<8; j++){
	if((*it).first[j] == c[i][j])
	  count2++;
      }
      if(count3 == count2 && count3 != 0)
	//      if(count == count2 && count != 0)
	sum += (*it).second;
    }
    it++;
  }
  cout << sum << endl;
}

int main(){
  while(cin >> n >> m && (n || m)){
    M.clear();
    sum = 0;
    for(int i=0; i<n; i++){
      cin >> s >> money;
      M[s] = money;
    }
    for(int i=0; i<m; i++)
      for(int j=0; j<8; j++)
	cin >> c[i][j];
    solve();
  }
  return 0;
}
