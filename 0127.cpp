#include <iostream>
using namespace std;

int main(){
  char c[6][6] = {
    {'a','b','c','d','e'},
    {'f','g','h','i','j'},
    {'k','l','m','n','o'},
    {'p','q','r','s','t'},
    {'u','v','w','x','y'},
    {'z','.','?','!',' '}};
  string s,s1;
  while(cin >> s){
    int flag = 0;
    s1.clear();
    for(int i=0; i<s.size(); i+=2){
      if(s.size() % 2 != 0 ){
	cout << "NA";
	break;
      }
      int a = s[i] - '0';
      int b = s[i+1] - '0';
      
      if((b > 5 || b <= 0) || (a > 6 || a <= 0)){
	cout << "NA";
	flag = 1;
	break;
      }
      s1 += c[a-1][b-1];
    
    }
    if(!flag)
    cout << s1 << endl;
    if(flag == 1)
      cout << endl;
  }
  return 0;
}
