#include <iostream>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

const char ope[] = "+-*";
int main(){
  string s;
  while(getline(cin,s)){
    if(s[0] == '0' && s[2] == '0' && s[4] == '0' && s[6] == '0')break;
