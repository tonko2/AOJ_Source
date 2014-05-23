#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class State{
public:
   int cnt;
   string data;

   bool operator < (State const &s) const{
      if(data == s.data) return cnt < s.cnt;
      else return data < s.data;
   }
};

string find(string a, string b, string c){
   string tmp = "", tmp2 = "";
   while(1){
      int pos = -1,pos2;
      for(int i=0; i<a.size(); i++){
         bool flag = false;
         for(int j=0; j<b.size(); j++){
            if(i+b.size() > a.size()){
               flag = true;
               break;
            }
            if(a[i+j] != b[j]) flag = true;
            if(flag)break;
         }
         if(!flag){
            pos = i;
            pos2 = i+b.size();
            break;
         }
      }
 
      if(pos == -1) return tmp+tmp2;
      tmp += a.substr(0,pos);
      tmp += c;
      tmp2 = a.substr(min(pos2,(int)a.size()));
      a = a.substr(pos+b.size(),a.size());
   }
}
int main(){
   int n;
   string a,b,s,e;
   pair<string,string>p[15];
   while(cin >> n && n){
      for(int i=0; i<n; i++){
         cin >> a >> b;
         p[i].first = a, p[i].second = b;
      }
 
      cin >> s >> e;
      int ans = -1;
      string tmp = "";
      set<State>se;
      State t;
      t.data = s, t.cnt = 0;
      se.insert(t);
      queue<set<State> >que;
      que.push(se);
      while(!que.empty()){
         set<State> S = que.front();
         que.pop();
         int cnt = S.cnt+1;
         for(int i=0; i<n; i++){
            tmp = find(S,p[i].first,p[i].second);
            if(m[tmp] || tmp == "" || tmp.size() > e.size())continue;
            if(tmp == e){
               ans = cnt;
               goto end;
            }
            m[tmp] = cnt;
            que.push(tmp);
         }
      }
     end:
      cout << ans << endl;
   }
   return 0;
}
