#include <iostream>
#include <string>
#include <set>
using namespace std;

int used[26][26];
bool t[26];
int n;

int dfs(int j){
   t[j] = true;
   int res = 1;
   for(int i=0; i<26; i++){
      if(used[j][i] && !t[i]) res += dfs(i);
   }
   return res;
}

int main(){
   while(cin >> n && n){
      set<char>se;
      int a[26],b[26],from,to;
      string s;
      for(int i=0; i<26; i++) t[i] = a[i] = b[i] = 0;
      fill(used[0],used[26],false);
      
      for(int i=0; i<n; i++){
         cin >> s;
         from = s[0]-'a';
         to = s[s.size()-1]-'a';
         se.insert(s[0]);
         se.insert(s[s.size()-1]);
         used[from][to]++;
         a[from]++;
         a[to]--;
      }

      //相対次数のチェック
      int sum = 0;
      bool flag = false;
      for(int i=0; i<26; i++){
         if(a[i] != 0){
            flag = true;
            goto end;
         }
      }

      //連結かどうかのチェック
      for(int i=0; i<26; i++){
         flag = true;
         fill(t,t+26,0);
         int cnt = dfs(i);
         if(cnt == se.size()){
            flag = false;
            goto end;
         }
      }
      
     end:
      if(flag) cout << "NG" << endl;
      else cout << "OK" << endl;
      
   }
   return 0;
}
