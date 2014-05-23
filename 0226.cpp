#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s1,s2;
  int count1,count2;

  while(cin >> s1 >> s2){
    count1 = 0;
    count2 = 0;

    if(s1[0] == '0' && s2[0] == '0')break;

    if(s1[0] == s2[0])count1++;
    if(s1[1] == s2[1])count1++;
    if(s1[2] == s2[2])count1++;
    if(s1[3] == s2[3])count1++;
    if(s1[0] == s2[1] || s1[0] == s2[2] || s1[0] == s2[3])count2++; 
    if(s1[1] == s2[0] || s1[1] == s2[2] || s1[1] == s2[3])count2++;
    if(s1[2] == s2[0] || s1[2] == s2[1] || s1[2] == s2[3])count2++;
    if(s1[3] == s2[0] || s1[3] == s2[1] || s1[3] == s2[2])count2++;
    
    cout << count1 << ' ' << count2 << endl;
  }

  return 0;
}
