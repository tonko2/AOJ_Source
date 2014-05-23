#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){

   string s;
   while(getline(cin,s)){
      if(s == "0")break;
      stringstream ss(s);
      int n,S;
      ss >> n;
      ss >> S;
      int value;
      vector<int>v;
      while(ss >> value) v.push_back(value);
      int x = 0;
      for(int i=0; i<n; i++) x ^= v[i];
      cout << x << endl;
   }
   return 0;
}
