#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int n,sum,a,b,c;
  string s1,s2,s3;

  cin >> n;

  for(int i=0; i<n; i++){
    s3 = "";
    c = 0;
    cin >> s1;
    cin >> s2;
  
  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());

  while(s1.length() != s2.length()){
    if(s1.length() > s2.length())
      s2 += '0';
    else if(s1.length() < s2.length())
      s1 += '0';
  }

  for(int i=0; i<s1.length(); i++){
    a = s1[i] - '0';
    b = s2[i] - '0';
    sum = a + b + c;
    s3 += (sum % 10) + '0';
    c = sum / 10;
  }
  if(c == 1)
    s3 += c + '0';
  reverse (s3.begin(),s3.end());
  
  
  
  if(s3.length() > 80)
    cout << "overflow" << endl;
  else
    cout << s3 << endl;
  }
  return 0;
}
