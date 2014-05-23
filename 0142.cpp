#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
   int n,array[5000];
   while(cin >> n && n){
      vector<int>v,v2;
      map<int,int>m;
      for(int i=1; i<=n-1; i++){
         int value = i * i % n;
         v.push_back(value);
         m[value] = 1;
      }

      for(int i=0; i<v.size(); i++){
         if(m[v[i]]){
            m[v[i]] = 0;
            v2.push_back(v[i]);
         }
      }

      int cnt[5000] = {0};
      for(int i=0; i<v2.size(); i++){
         for(int j=i+1; j<v2.size(); j++){
            int value = v2[i] - v2[j];
            if(value < 0) value += n;
            if(value > (n-1)/2) value = n - value;
            cnt[value]++;
         }
      }
      
      for(int i=1; i<=(n-1)/2; i++)
         cout << cnt[i]*2 << endl;
      
   }
   return 0;
}
