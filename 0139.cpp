#include <iostream>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s;
    int count=0,count2=0,count3 = 0,count4 = 0,ans1=0, ans2=0;
    int flag1 = 0,flag2 = 0;
    
    if(s[0] == '>' && s[1] == '\'') flag1 += 1;
    else if(s[0] == '>' && s[1] == '^') flag2 += 1;
    
    for(int j=2; j<s.size(); j++){
      if(s[j] == '=') count++;
      else count4++;
      
      if(s[j] == 'Q' && s[j+1] == '='){
	count2++;
	j += 1;
      }
      else count3++;
      
      if(flag1 == 1){
	if(s[j] == '#'){
	  flag1 += 1;
	  ans1 = count;
	  count = 0;
	}
      }
      else if(flag1 == 2){
	if(s[j] == '~'){
	  ans2 = count;
	}
      }
    }
    if(flag1 == 2 && s[s.size()-1] == '~' && ans1 == ans2 && ans1 != 0 &&
       ans2 != 0 && count4 == 2)
      cout << "A" << endl;
    else if(flag2 == 1 && s[s.size()-1] == '~' && s[s.size()-2] == '~' &&
	    count2 != 0 && count3 == 2)
      cout << "B" << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
