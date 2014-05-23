#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)
typedef pair<int,int> P;
string grid[12];
int ans;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<P> v;
bool used[12][6];

void print(){
   rep(i,12){
      rep(j,6){
         cout << grid[i][j];
      }
      cout << endl;
   }
}
void drop(){
   while(true){
      bool update = false;

      rep(i,12){
         rep(j,6){
            if(i+1 > 11)break;
            if(grid[i][j] != '.' && grid[i+1][j] == '.'){
               grid[i+1][j] = grid[i][j];
               grid[i][j] = '.';
               update = true;
            }
         }
      }
      
      if(!update)break;
   }
}

void dfs(int x, int y){
   v.push_back(P(x,y));
   used[y][x] = true;
   rep(i,4){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 6 || ny >= 12)continue;
      if(used[ny][nx])continue;
      if(grid[ny][nx] == grid[y][x]) dfs(nx,ny);
   }
}

void del2(){
   rep(i,v.size()){
      int x = v[i].first, y = v[i].second;
      rep(j,4){
         int nx = x + dx[j], ny = y + dy[j];
         if(nx < 0 || ny < 0 || nx >= 6 || ny >= 12)continue;
         if(grid[ny][nx] == 'O') grid[ny][nx] = '.';
      }
   }
}

bool del(){

   bool res = false;
   while(true){
      bool update = false;
      
      rep(i,12){
         rep(j,6){
            if(grid[i][j] == '.' || grid[i][j] == 'O')continue;
            v.clear();
            fill(used[0],used[12],0);
            dfs(j,i);
            int n = v.size();
            if(n <= 3)continue;
//            cout << "i = " << i << " j = " << j << endl;
            res = true;
            update = true;
            rep(k,v.size()){
               int x = v[k].first, y = v[k].second;
               grid[y][x] = '.';
            }
            
            del2();
         }
      }
      
      if(!update) break;
   }
   return res;
}

void solve(){
   ans = 0;
   while(del()){
      ans++;
      drop();
   }
   cout << ans << endl;
}

int main(){
   int n;
   cin >> n;
   string dummy;
   getline(cin,dummy);
   while(n--){
      string in;
      rep(i,12){
         getline(cin,in);
         grid[i] = in;
      }
      solve();
//      print();
   }
   return 0;
}
