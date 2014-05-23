#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int n,value;
  string s1,s2,dummy="00000000";
  char s3[1000];
  cin >> n;
  for(int T=1; T<=n; T++){
    cin >> value;
    cout << "Case " << T << ":" << endl;
    for(int i=0; i<10; i++){
      s2 = "";
      value = value*value;
      sprintf(s3,"%d",value);
      s1 = dummy+s3;
      for(int j=s1.size()-3; j>s1.size()-7; j--) s2 += s1[j];
      reverse(s2.begin(),s2.end());
      stringstream ss;
      ss << s2;
      ss >> value;
      cout << value << endl;
    }
  }
  return 0;
}
