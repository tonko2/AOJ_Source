#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
 
int main(){
  int n;
  char initial;
  string str,s;
  while(cin >> n && n){
    map<string,int>m;
    cin.ignore();
    for(int i=0; i<n; i++){
      getline(cin,str);
      stringstream ss;
      ss << str;
      while(ss >> s){
    m[s] -= 1;
      }
    }
    cin >> initial;
     
    map<string,int>:: iterator it=m.begin();
 
    vector<pair<int,string> >v; 
    while(it != m.end()){
      v.push_back(make_pair(it->second,it->first));
      it++;
    }   
    int cnt = 0;
 
    sort(v.begin(),v.end());
 
    for(int i=0; i<v.size(); i++){
      if(v[i].second[0] == initial){
    if(cnt == 0){
      cout << v[i].second;
      cnt++;
    } else {
      cout << " " << v[i].second;
      cnt++;
    }
    if(cnt == 5)break;
      }
    }  
    if(cnt == 0) cout << "NA";
    cout << endl;
  }
  return 0;
}
