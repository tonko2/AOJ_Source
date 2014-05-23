#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<char,vector<int> >m;
map<char,int> m2;

pair<int,int> diff(){
   map<char,vector<int> >::iterator it = m.begin();
   int s = 1<<29;
   int e = 0;
   while(it != m.end()){
      vector<int>tmp = it->second;
      for(int i=0; i<tmp.size(); i++){
         s = min(s,tmp[i]);
         e = max(e,tmp[i]);
      }
      it++;
   }
   return pair<int,int>(s,e);
}

int main(){
   string s;
   int c = 0;
   while(getline(cin,s)){
      vector<string>v;
      if(s.size() == 0)break;
      
      v.push_back(s);
      
      while(getline(cin,s)){
         if(s.size() == 0)break;
         v.push_back(s);
      }

      string str;
      for(int i=0; i<v.size(); i++) str += v[i];
      m2.clear();
      string key;
      getline(cin,key);
      string key2 = key;
      sort(key2.begin(),key2.end());
      key2.erase(unique(key2.begin(),key2.end()),key2.end());
      
      for(int i=0; i<key.size(); i++) m2[key[i]]++;

      m.clear();
      cin.ignore();
      bool flag = false;
      int cnt = 0;
      pair<int,pair<int,int> >ans;
      ans.first = 1<<29;
      for(int i=0; i<str.size(); i++){
         if(!m2.count(str[i]))continue;
         if(m[str[i]].size() < m2[str[i]]){
            m[str[i]].push_back(i);
         } else {
            int n = m[str[i]].size();
            for(int j=0; j<n-1; j++){
               m[str[i]][j] = m[str[i]][j+1];
            }
            m[str[i]][n-1] = i;
         }
         int sum = 0;
         for(int j=0; j<key2.size(); j++){
            sum += m[key[j]].size();
         }
         
         if(!flag && sum == key.size()){
//            cout << "sum = " << sum << endl;
            flag = true;
         }

         if(!flag)continue;
         pair<int,int>p = diff();
         if(p.second-p.first < ans.first){
            ans.first = p.second-p.first;
            ans.second = p;
         }
      }

      if(ans.first == 1<<29) goto end;
      m.clear();
      cnt = 0;
      flag = false;

      for(int i=0; i<str.size(); i++){
         if(!m2.count(str[i]))continue;
         if(m[str[i]].size() < m2[str[i]]){
            m[str[i]].push_back(i);
         } else {
            int n = m[str[i]].size();
            for(int j=0; j<n-1; j++){
               m[str[i]][j] = m[str[i]][j+1];
            }
            m[str[i]][n-1] = i;
         }
         int sum = 0;
         for(int j=0; j<key2.size(); j++){
            sum += m[key[j]].size();
         }
            
         if(!flag && sum == key.size()) flag = true;
         if(!flag)continue;
         pair<int,int>p = diff();
         if(p.second-p.first == ans.second.second-ans.second.first)cnt++;
      }

     end:
      cout << cnt << endl;
      if(cnt != 0){
         cout << endl;
         string tmp = str.substr(ans.second.first,ans.second.second-ans.second.first+1);
         int cc = 0;
         for(int i=0; i<tmp.size(); i++){
            cc++;
            cout << tmp[i];
            if(cc != 0 && cc % 72 == 0){cout << endl; cc = 0;}

         }
         if(cc) cout << endl;
      }
      cout << endl;
   }
   return 0;
}
