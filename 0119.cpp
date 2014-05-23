#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>

const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

class State{
public:
   vector<int>prev,next;
};

bool used[21];
State a[21];
int m,n;
vector<int>ans;

void dfs(int N, int x, vector<int> v){

   if(N == m){
      ans = v;
      throw 100;
   }

   for(int i=0; i<a[x].prev.size(); i++){
      int index = a[x].prev[i];
      if(!used[index]) return;
   }

   for(int i=0; i<a[x].next.size(); i++){
      int index = a[x].next[i];
      if(used[index]) return;
   }

   for(int i=1; i<=m; i++){
      if(used[i])continue;
      vector<int>tmp;
      tmp = v;
      tmp.push_back(i);
      used[i] = true;
      dfs(N+1,i,tmp);
      used[i] = false;
   }
   
}

int main(){

   cin >> m >> n;
   
   for(int i=0; i<n; i++){
      int x,y;
      cin >> x >> y;
      a[x].next.push_back(y);
      a[y].prev.push_back(x);
   }

   try{
      for(int i=1; i<=m; i++){
	 dfs(0,i,vector<int>());
      }
   }catch(...){}

   
   for(int i=0; i<(int)ans.size(); i++){
      if(i == 0) cout << ans[i];
      else cout << " " << ans[i];
   }
   cout << endl;

  return 0;
}
