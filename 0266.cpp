#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef pair<char,int> P;
map<P,char>m;

void init(){
   m[P('A',0)] = 'X';
   m[P('A',1)] = 'Y';
   m[P('X',1)] = 'Z';
   m[P('Y',0)] = 'X';
   m[P('Z',0)] = 'W';
   m[P('Z',1)] = 'B';
   m[P('W',0)] = 'B';
   m[P('W',1)] = 'Y';
   m[P('B',0)] = 'Y';
   m[P('B',1)] = 'X';
}

int main(){
   init();
   string s;
   while(cin >> s){
      if(s == "#")break;
      bool f = false;

      char now = 'A';
      for(int i=0; i<s.size(); i++){
	 int next = s[i] - '0';
	 if(!m.count(P(now,next))){
	    f = true;
	    break;
	 }
	 now = m[P(now,next)];
      }

      if(f || now != 'B') cout << "No" << endl;
      else cout << "Yes" << endl;
      
   }
}
