#include <iostream>
#include <map>
#include <queue>
using namespace std;

string s;
map<string,int>m;
map<string,bool>used;

bool equals(string s){
   for(int i=0; i<s.size()-1; i++){
      if(s[i] != s[i+1]) return false;
   }
   return true;
}
int bfs(){
   queue<string>que;
   que.push(s);
   m[s] = 0;
   used[s] = true;
   while(!que.empty()){
      string u = que.front();que.pop();
      if(equals(u)) return m[u];
      string tmp,tmp2;
      for(int i=0; i<u.size()-1; i++){
         if(u[i] != u[i+1]){
            if(u[i] == 'r'){
               if(u[i+1] == 'b')  tmp = "g";
               else if(u[i+1] == 'g') tmp = "b";
            } else if(u[i] == 'g'){
               if(u[i+1] == 'b') tmp = "r";
               else if(u[i+1] == 'r') tmp = "b";
            } else if(u[i] == 'b'){
               if(u[i+1] == 'r') tmp = "g";
               else if(u[i+1] == 'g') tmp = "r";
            }
            tmp2 = u;
            tmp2[i] = tmp2[i+1] = tmp[0];
            if(!used[tmp2]){
               m[tmp2] = m[u]+1;
               used[tmp2] = true;
               que.push(tmp2);
            }
         }
         
      }
      
   }
   return -1;
}

int main(){
   while(cin >> s){
      if(s == "0")break;
      m.clear(),used.clear();
      int ans = bfs();
      if(ans == -1) cout << "NA" << endl;
      else cout << ans << endl;
   }   
   return 0;
}

