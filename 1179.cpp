#include <iostream>
using namespace std;


int calc(int y){
   int data = 0;
   bool flag = false;
   for(int i=1; i<y; i++){
      if(i % 3 == 0) flag = true;
      else flag = false;
      for(int j=1; j<=10; j++){
         if(!flag){
            int loop = 20;               
            if(j % 2 == 0) loop = 19; 
            for(int k=1; k<=loop; k++){
               data++;
            }
         } else {
            for(int k=1; k<=20; k++){
               data++;
            }
         }
      }
   }
   return data;
}

int main(){
   int n,y,m,d;
   cin >> n;
   int data = calc(1000); data++;
   
   for(int t=0; t<n; t++){
      cin >> y >> m >> d;
      int data2 = calc(y);

      bool flag = false;
      if(y % 3 == 0) flag = true;
      
      for(int j=1; j<m; j++){
         if(!flag){
            int loop = 20;               
            if(j % 2 == 0) loop = 19; 
            for(int k=1; k<=loop; k++){
               data2++;
            }
         } else {
            for(int k=1; k<=20; k++){
               data2++;
            }
         }
      }

      for(int i=1; i<=d; i++){
         data2++;
      }
      cout << data - data2 << endl;
   }
   return 0;
}
