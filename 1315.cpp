#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
   int n;
   while(cin >>n && n){
      int ans = 0;
      int v[1001];
      int d[1001];
      memset(v,0,sizeof(v));
      memset(d,-1,sizeof(d));
      int prevm = -1,prevd = -1;
      while(n--){
         char e;
         int M,D,h,m,p;
         scanf("%d/%d %d:%d %c %d",&M,&D,&h,&m,&e,&p);
         int t = 60*h + m;

         if(prevm != M || prevd != D){
            memset(d,-1,sizeof(d));
         }
         
         if(e == 'I' && p == 0) d[0] = t;
         else if(e == 'I') d[p] = t;
         else if(e == 'O' && p == 0){
            for(int i=1; i<=1000; i++){
               if(d[i] == -1)continue;
               v[i] += t - max(d[0],d[i]);
            }
            d[0] = -1;
         } else if(e == 'O'){
            if(d[0] == -1){d[p] = -1; continue;}
            v[p] += t - max(d[0],d[p]);
            d[p] = -1;
         }
         prevm = M, prevd = D;
      }
      
      for(int i=1; i<=1000; i++) ans = max(ans,v[i]);   

      if(ans == -1) ans = 0;
      cout << ans << endl;
   }
   return 0;
}
