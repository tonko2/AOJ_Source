#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main(){
   int n,m;
   while(cin >> n >> m,n|m){
      vector<string>v;
      for(int i=0; i<n; i++){
         string s;
         cin >> s;
         v.push_back(s);
      }

      vector<string>v2;
      vector<string>v3;
      vector<string>v4;

      //m = 2
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            if(i == j)continue;
            string str = v[i]+v[j];
            v2.push_back(str);
         }
      }
      sort(v2.begin(),v2.end());
      v2.erase(unique(v2.begin(),v2.end()),v2.end());
      
      //m = 3
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            for(int k=0; k<v.size(); k++){
            if(i == j || j == k || i == k)continue;
            string str = v[i]+v[j]+v[k];
            v3.push_back(str);
            }
         }
      }
      sort(v3.begin(),v3.end());
      v3.erase(unique(v3.begin(),v3.end()),v3.end());
      
      //m = 4
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            for(int k=0; k<v.size(); k++){
               for(int l=0; l<v.size(); l++){
                  if(i == j || i == k || i == l ||
                     j == k || j == l || k == l)continue;
            string str = v[i]+v[j]+v[k]+v[l];
            v4.push_back(str);
               }
            }
         }
      }

      sort(v4.begin(),v4.end());
      v4.erase(unique(v4.begin(),v4.end()),v4.end());
      
      int size;
      if(m == 2) size = v2.size();
      else if(m == 3) size = v3.size();
      else if(m == 4) size = v4.size();
      
      cout << size << endl;

   }
   return 0;
}
