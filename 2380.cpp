#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <cctype>
#include <assert.h>
#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

class State{
public:
   char field[4][4];
   int cnt;
   bool operator < (State const &s) const {
      return true;
   }
   
};

int ans;
int getMax(char a[][4]){
   int res = 0;
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         if(a[i][j] >= '0' && a[i][j] <= '9' && a[i][j] <= '4')
            res = max(res,a[i][j]-'0');
         else res = max(res,5);
      }
   }

   return res;
}

void change(State &a){
   bool flag = false;
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         if(a.field[i][j] >= '0' && a.field[i][j] <= '9' &&
            a.field[i][j] <= '4')continue;         
            a.field[i][j] = '0';
            for(int k=0; k<4; k++){
               int nx = j + dx[k], ny = i + dy[k];
               while(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
                  if(a.field[ny][nx] > '0'){
                     a.field[ny][nx]++;

                     flag = true;
                     break;
                  }
                  nx += dx[k];
                  ny += dy[k];
               }
            }
         }
      }
   if(!flag)return;
   else change(a);
}

void print(State tmp){
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         cout << tmp.field[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

int bfs(State obj){
   queue<State>que;
   que.push(obj);
   int res = 1<<29;
   while(!que.empty()){
      State tmp = que.front();
      int cnt = tmp.cnt;
      que.pop();
      int Max = getMax(tmp.field);
      if(Max == 0){
         res = cnt;
         break;
      }

//      print(tmp);

      if(Max == 5){
         State tmp2 = tmp;
         change(tmp2);
         que.push(tmp2);
      }
      
      if(cnt < 5){
         for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
               if(tmp.field[i][j] == '0')continue;
               tmp.field[i][j]++;
               tmp.cnt++;
               que.push(tmp);
               tmp.cnt--;
               tmp.field[i][j]--;
            }
         }
      }
   }
   return res;
}
int main(){
   State obj;
   for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
         int in;
         cin >> in;
         obj.field[i][j] = in+'0';
      }
   }
   
   obj.cnt = 0;
   int ans = bfs(obj);
   if(ans > 5) cout << -1 << endl;
   else cout << ans << endl;
   return 0;
}
