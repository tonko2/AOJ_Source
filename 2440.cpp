#include <iostream>
using namespace std;

const int MAX = 260;
int main(){
   int n,m;
   string s[MAX],in;
   cin >> n;
   for(int i=0; i<n; i++) cin >> s[i];
   cin >> m;
   bool flag = false,flag2 = false;
  
   for(int i=0; i<m; i++){
      cin >> in;
      flag2 = false;
      for(int j=0; j<n; j++){
         if(s[j] == in){
            if(!flag) flag = true,cout << "Opened by " << in << endl;
            else flag = false,cout << "Closed by " << in << endl;
            flag2 = true;
            break;
         }
      }
      if(!flag2) cout << "Unknown " << in << endl;
   }
   
   return 0;
}
