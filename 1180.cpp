#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
   string s,max,min;
   int keta;
   vector<string>v;
   
   while(cin >> s >> keta){
      if(s == "0" && keta == 0)break;
      string data = s;
      int cnt = 0;
      for(int i=data.size(); i<keta; i++) data += '0';
      v.clear();
      v.push_back(data);
      min = max = data;
      while(1){
         cnt++;
         sort(max.begin(),max.end());
         reverse(max.begin(),max.end());
         sort(min.begin(),min.end());
         int Max = atoi(max.substr(0,max.size()).c_str());
         int Min = atoi(min.substr(0,min.size()).c_str());
         int res = Max - Min;
         ostringstream os;
         os << res;
         data = os.str();
         for(int i=0; i<v.size(); i++){
            if(data == v[i]){
               cout << i << " " << data << " " << cnt-i << endl;
               goto end;
            }
         }
         
         v.push_back(data);
         min = max = data;
         for(int i=max.size(); i<keta; i++){
            min += '0';
            max += '0';
         }
      }
     end:;
   }
   return 0;
}
