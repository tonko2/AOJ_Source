#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int flag[1000000];

int main(){
   int p,q;
   while(cin >> p >> q){
      vector<int>cnt;
      int tmp;
      memset(flag,-1,sizeof(flag));
      p = p % q;
      flag[p] = 0;
      p *= 10;
      while(1){
         cnt.push_back(p/q);
         p %= q;
         if(!p){
            tmp = -1;
            break;
         } else if(flag[p] >= 0){
            tmp = flag[p];
            break;
         } else {
            flag[p] = cnt.size();
            p *= 10;
         }
      }
      if(tmp == -1){
         for(int i=0; i<cnt.size(); i++) cout << cnt[i];
         cout << endl;
      } else{
         for(int i=0; i<cnt.size(); i++) cout << cnt[i];
         cout << endl;
         for(int i=0; i<tmp; i++) cout << " ";
         for(int i=tmp; i<cnt.size(); i++) cout << '^';
         cout << endl;
      }
      
   }
   return 0;
}
