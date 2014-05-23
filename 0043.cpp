#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string s,dummy;
bool used[13];
vector<int>v;
int cnt2,cnt3,flag;
bool dfs(){
  if(cnt2 == 3){
    flag++;
    cnt2 = 0;
  }
  if(cnt3 == 3){
    flag++;
    cnt3 = 0;
  }
  
  for(int i=0; i<dummy.size(); i++){
    fill(used,used+14,0);
    used[i] = 1;
    for(int j=0; j<dummy.size(); j++){
      if(cnt3 == 1 && !used[j] && dummy[i] == dummy[j]){
	cnt2++;
	used[j] = 1;
      }

}
int main(){
  int cnt;
  while(cin >> s){

    for(int i=1; i<=9; i++){
      dummy = s;
      cnt = 0;
      for(int j=0; j<dummy.size(); j++){
	if(i+'0' == dummy[j])cnt++;
      }
      if(cnt == 4)continue;
      dummy += i+'0';
      sort(dummy.begin(),dummy.end());
      cout << dummy << endl;
      v.clear();
      for(int j=0; j<dummy.size(); j++){
	cnt2 = 1;
	cnt3 = 1;
	flag = 0;
	fill(used,used+14,0);
	used[j] = 1;
	if(dfs(dummy[j])) v.push_back(i);
      }
    }
    if(v.size()){
      cout << v[0];
      for(int i=1; i<v.size(); i++)
	cout << ' ' << v[i];
      cout << endl;
    }
    else cout << '0' << endl;
  }
  return 0;
}
