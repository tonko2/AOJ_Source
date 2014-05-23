#include <iostream>
using namespace std;
 
const int MAX = 10010;
int tmp[MAX];
int array[MAX];
bool visit[MAX];
 
int main(){
   int n;
   while(cin >> n && n){
      for(int i=0; i<n; i++) cin >> array[i];
      for(int i=0; i<n; i++) tmp[i] = array[i];
      int ans = n,count;
 
      for(int i=0; i<n; i++){
         fill(visit,visit+n,false);
         for(int k=0; k<n; k++) tmp[k] = array[k];
         bool ok = false;
         count = 0;
         if(n > i+3 && array[i+1] == array[i+2] &&
            array[i+2] == array[i+3]){
            ok = true;
            tmp[i] = array[i+1];
         }
 
         else if(i+2 < n && i-1 >= 0 && array[i-1] == array[i+1] &&
                 array[i+1] == array[i+2]){
            tmp[i] = array[i+1];
            ok = true;
         }
     
         else if(i+1 < n && i-2 >= 0 && array[i-2] == array[i-1] &&
                 array[i-1] == array[i+1]){
            tmp[i] = array[i+1];
            ok = true;
         }
 
         else if(i < n && i-3 >= 0 && array[i-3] == array[i-2] &&
                 array[i-2] == array[i-1]){
            tmp[i] = array[i-1];
            ok = true;
         }
     
         if(!ok) continue;
         while(true){
            bool update = false;
            int cnt2 = 0,cnt = 0;
            for(int j=0; j<n-1; j++){
               cnt2 = 2;
               cnt = j+1;
               while(n > cnt){
                  if(visit[cnt]){
                     cnt++;
                     continue;
                  }
                  if(tmp[j] == tmp[cnt]) cnt++,cnt2++;
                  else break;
               }
 
               if(cnt2 >= 4){
                  for(int k=j; k<cnt; k++) visit[k] = true;
                  update = true;
               }
            }
            if(!update) break;
         }
 
         for(int k=0; k<n; k++) if(!visit[k])count++;
         ans = min(ans,count);
 
      }
      cout << ans << endl;
   }
   return 0;
}
