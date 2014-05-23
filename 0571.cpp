#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;

  int count_J,count_O,count_I;
  count_J = count_O = count_I = 0;
  bool flag1 = false,flag2 = false,flag = true,flag3 = false;
  int ans = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'J' && flag){
      count_J++;
      flag1 = true;
    }
    
    else if(s[i] == 'O' && flag1){
      count_O++;
      flag2 = true;
      flag = false;
    }
    
    else if(s[i] == 'I' && flag2){
      count_I++;
      flag1 = false,flag = false;
    }
    
    else{
      if(count_J == count_O && count_O == count_I);
      
      else if(count_J < count_O){
	count_O = 0;
      }

      else if(count_J >= count_O && count_O > count_I) count_O = 0;
      
      if(count_J > 0 && count_O > 0 && count_I > 0)
	ans = max(ans,min(count_J,min(count_O,count_I)));
      count_J = count_O = count_I = 0;
      flag = true;
      flag1 = false;
      flag2 = false;
      if(s[i] == 'J'){
	count_J++;
	flag1 = true;
      }
      else if(s[i] == 'O'){
	count_O++;
	flag = false;
	flag2 = true;
      } 
      if(s[i] == 'I'){
	count_I++;
	flag1 = false;
	flag = false;
      }

    }
    
    if(i == s.size()-1){
      if(count_J == count_O && count_O == count_I);
      
      else if(count_J < count_O){
	count_O = 0;
      }
      
      else if(count_J >= count_O && count_O > count_I) count_O = 0;

      if(count_J > 0 && count_O > 0 && count_I > 0)
	ans = max(ans,min(count_J,min(count_O,count_I)));
      count_J = count_O = count_I = 0;
    }

  }
  cout << ans << endl;
  return 0;
}
