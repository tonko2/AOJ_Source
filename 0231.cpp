#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Bridge{
   int w,a,b;
   Bridge(){}
   Bridge(int w, int a, int b):w(w),a(a),b(b){}
};

int main(){
   int n;
   while(cin >> n && n){
      int from[1000],to[1000];
      Bridge x[1000];
      vector<int>v;
      for(int i=0; i<n; i++){
         int w,a,b;
         cin >> w >> a >> b;
         x[i] = Bridge(w,a,b);
         from[i] = a;
         to[i] = b;
         v.push_back(a);
         v.push_back(b);
      }

      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());

      for(int i=0; i<v.size(); i++){
         from[i] = lower_bound(v.begin(),v.end(),from[i])-v.begin();
         to[i] = lower_bound(v.begin(),v.end(),to[i])-v.begin();
      }

      int weight[1000];
      fill(weight,weight+1000,0);
      for(int i=0; i<n; i++){
         for(int j=from[i]; j<to[i]; j++) weight[j] += x[i].w;
      }

      bool flag = false;
      for(int i=0; i<1000; i++) if(weight[i] > 150) flag = true;

      if(flag) cout << "NG" << endl;
      else cout << "OK" << endl;
   }
   return 0;
}
