#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int n,m;
stack<int> pos[3];

int dfs(int from, int to){
   int res = 1;

   while(pos[0].size() != n && pos[2].size() != n && res < m){
      for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
            if(i == j)continue;
            if(to == i && from == j)continue;
            if(pos[i].size() == 0)continue;
            if(pos[j].size()!=0 && pos[i].top() < pos[j].top())continue;
            if(abs(i-j) != 1)continue;
            from = i, to = j;
            pos[j].push(pos[i].top());
            pos[i].pop();
            goto end;
         }
      }
     end:;
      res++;
   }
   return res;
}
int main(int argc, char *argv[])
{
   while(cin >> n >> m,n|m){
      
      for(int i=0; i<3; i++){
         while(!pos[i].empty()){
            pos[i].pop();
         }
      }
      
      stack<int>tmp[3];
      for(int i=0; i<3; i++){
         int k;
         cin >> k;
         for(int j=0; j<k; j++){
            int in;
            cin >> in;
            pos[i].push(in);
            tmp[i].push(in);
         }
      }

      if(pos[0].size() == n || pos[2].size() == n){
         cout << 0 << endl;
         continue;
      }
      int ans = 1<<29;
      for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
            if(i == j)continue;
            if(pos[i].size() == 0)continue;
            if(pos[j].size() != 0 && pos[i].top() < pos[j].top())continue;
            if(abs(i-j) != 1)continue;

            pos[j].push(pos[i].top());
            pos[i].pop();
            ans = min(ans,dfs(i,j));
            for(int i=0; i<3; i++) pos[i] = tmp[i];
         }
      }
      cout << (ans>=m?-1:ans) << endl;
   }
   return 0;
}
