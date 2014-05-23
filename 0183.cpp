#include <iostream>
using namespace std;

int main(){
  char s[3][4];

  while(1){
    char ans = ' ';
    for(int i=0; i<3; i++){
      cin >> s[i];
      if(s[0][0] == '0')return 0;
    }

    if(s[0][0] != '+'){
      if(s[0][0] == s[1][1] && s[1][1] == s[2][2]) ans = s[0][0];
    }
    if(s[0][2] != '+'){
      if(s[0][2] == s[1][1] && s[1][1] == s[2][0]) ans = s[0][2];
    }

    for(int i=0; i<3; i++){
      if(s[i][0] != '+'){
	if(s[i][0] == s[i][1] && s[i][1] == s[i][2]) ans = s[i][0];
      }

      if(s[0][i] != '+'){
	if(s[0][i] == s[1][i] && s[1][i] == s[2][i]) ans = s[0][i];
      }
    }

    if(ans == ' ')
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
						       
