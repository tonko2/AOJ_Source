#include <iostream>
using namespace std;

int a[52];

int main(){
   fill(a,a+52,0);
   a[9] = 1;
   int cut = 0;
   while(true){
      int tmp[52];
      int cnt = 0;
      
      for(int i=0; i<26; i++){
	 tmp[cnt++] = a[i];
	 tmp[cnt++] = a[i+26];
      }
      
      for(int i=0; i<56; i++) a[i] = tmp[i];
      cut++;
      if(a[9] == 1)break;

      
   }

   cout << cut << endl;
   
   return 0;
}
