#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int> >v;
string str = "0ABCDEFGHIJK0";
map<string,int>m;

void init(){
   v.resize(13);
   v[0].push_back(2);
   v[1].push_back(2),v[1].push_back(5);
   v[2].push_back(0),v[2].push_back(1),v[2].push_back(3),v[2].push_back(6);
   v[3].push_back(2),v[3].push_back(7);
   v[4].push_back(5);
   v[5].push_back(1),v[5].push_back(4),v[5].push_back(6),v[5].push_back(9);
   v[6].push_back(2),v[6].push_back(5),v[6].push_back(7),v[6].push_back(10);
   v[7].push_back(3),v[7].push_back(6),v[7].push_back(8),v[7].push_back(11);
   v[8].push_back(7);
   v[9].push_back(5),v[9].push_back(10);
   v[10].push_back(6),v[10].push_back(9),v[10].push_back(11),v[10].push_back(12);
   v[11].push_back(7),v[11].push_back(10);
   v[12].push_back(10);
   
   queue<pair<int,string> >que;
   que.push(pair<int,string>(0,str));

   while(!que.empty()){
      int cnt = que.front().first;
      string s = que.front().second;
      que.pop();
      if(cnt > 10)continue;
      if(m.count(s))continue;
      m[s] = cnt;

      for(int i=0; i<s.size(); i++){
         string tmp = s;
         if(s[i] == '0'){
            for(int j=0; j<v[i].size(); j++){
               swap(s[i],s[v[i][j]]);
               que.push(pair<int,string>(cnt+1,s));
               swap(s[i],s[v[i][j]]);
            }
         }
      }
   }
}

int bfs(string s){
   set<string>se;
   queue<pair<int,string> >que;
   que.push(pair<int,string>(0,s));
   
   while(!que.empty()){
      int cnt = que.front().first;
      string t = que.front().second;
      que.pop();
      
      if(m.count(t)) return cnt + m[t];
      if(t == str) return cnt;
      if(cnt > 10) continue;
      if(se.count(t))continue;
      se.insert(t);
      
      for(int i=0; i<t.size(); i++){
         if(t[i] == '0'){
            for(int j=0; j<v[i].size(); j++){
               swap(t[i],t[v[i][j]]);
               que.push(pair<int,string>(cnt+1,t));
               swap(t[i],t[v[i][j]]);
            }
         }
      }
   }
   return 21;
}

int main(){
   init();
   int a[13];
   while(cin >> a[0]){
      if(a[0] == -1)break;
      for(int i=1; i<13; i++){
         cin >> a[i];
      }

      string s = "";
      for(int i=0; i<13; i++){
         if(a[i] == 0) {s += '0'; continue;}
         s += ('A'+(a[i]-1));
      }
      
      int ans = bfs(s);
      if(ans > 20) cout << "NA" << endl;
      else cout << ans << endl;

   }   
   return 0;
}
