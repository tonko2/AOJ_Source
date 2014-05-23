#include <iostream>
#include <vector>
using namespace std;

int main(){
  string s;
  int ans,total1,total2;
  vector<int>v,total;
  while(getline(cin,s)){
    ans = 0;
    v.clear();
    total.clear();
    if(s == "0")break;

    for(int i=0; i<s.size(); i++){
      if(i+1 != s.size() && s[i+1] != ' '){
	v.push_back(10);
	i++;
      }
      else
	v.push_back(s[i]-'0');
      i++;
    }
    total1 = total2 = 0;
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
      if(v[i] == 1){
	cnt++;
      }
      else if(v[i] >= 10){
	total1 += 10;
      }
      else{
	total1 += v[i];
      }
    }

    bool flag = false;    
    if(total1+cnt<= 21){
      ans = total1+cnt;
    }

    if(cnt > 0 && ans == 0) flag = true;
    if(flag)goto end;
      for(int i=0; i<cnt; i++){
	if(ans+10 <= 21) ans = ans+10;      
	else break;	
      }
  end:;
    cout << ans << endl;
  }
  return 0;
}
