#include <iostream>
//#include <cstring>
using namespace std;

int main(){
  int n;
  string s1,s2;
  while(cin >> s1 >> s2){
    int ans = 0;
    for(int i=0; i<s1.size(); i++){
      int cnt = 0;
      string tmp = s1.substr(i,s1.size()-i);
      for(int j=0; j<min(tmp.size(),s2.size()); j++){
	if(tmp[j] == s2[j])cnt++;
	else cnt = 0;
      ans = max(ans,cnt);
      }
    }
    for(int i=0; i<s2.size(); i++){
      int cnt = 0;
      string tmp = s2.substr(i,s2.size()-i);
      for(int j=0; j<min(s1.size(),tmp.size()); j++){
	if(tmp[j] == s1[j])cnt++;
	else cnt = 0;
      ans = max(ans,cnt);
      }
    } 
    cout << ans << endl;
  }
  return 0;
}
