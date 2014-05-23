#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int n,k,array[101];
   while(cin >> n >> k,n|k){
      for(int i=0; i<n; i++) cin >> array[i];

      int Max1,Max2;
      Max1 = Max2 = 0;
      for(int i=0; i<n-k+1; i++){
         int value = 1;
         for(int j=0; j<k; j++){
            value *= array[i+j];
         }
         Max1 = max(Max1,value);
      }
      
      for(int i=0; i<n-1; i++){
         for(int j=i+1; j<n; j++){
            swap(array[i],array[j]);
            for(int m=0; m<n-k+1; m++){
               int value = 1;
               for(int l=0; l<k; l++){
                  value *= array[m+l];
               }
               Max2 = max(Max2,value);
            }
            swap(array[i],array[j]);
         }
      }
      if(Max2 - Max1 < 0) cout << "NO GAME" << endl;
      else cout << Max2 - Max1 << endl;
      
   }
   return 0;
}
