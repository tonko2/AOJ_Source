#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {-1,-1,0,1,1,1,0,-1};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int g[20][20];
bool used[20][20];
int c,c2,X,Y;
int n;
vector<pair<pair<int,int>,pair<int,int> > >v;

void dfs(int x, int y, int num){
   used[y][x] = true;
   c2++;
   for(int i=0; i<4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 10 || ny >= 10)continue;
      if(used[ny][nx])continue;
      if(g[ny][nx] == 0){
         used[ny][nx] = true;
         c++;
         X = nx, Y = ny;
      } else if(g[ny][nx] == num){
         dfs(nx,ny,num);
      }
   }
}

void clear(){
   for(int i=0; i<n; i++){
      for(int j=0; j<i+1; j++){
         if(g[i][j] == 0) used[i][j] = false;
      }
   }
}
int main(){
   int num;
   while(cin >> n >> num,n|num){
      string dummy;
      getline(cin,dummy);
      fill(g[0],g[20],-1);
      fill(used[0],used[20],false);
      
      for(int i=0; i<n; i++){
         string s;
         getline(cin,s);
         stringstream ss(s);
         int value;
         int cnt = 0;
         while(ss >> value){
            g[i][cnt++] = value;
         }
      }

      v.clear();


      
      for(int i=0; i<n; i++){
         for(int j=0; j<i+1; j++){
            if(used[i][j])continue;
            pair<pair<int,int>,pair<int,int> >p;
            c = c2 = 0;
            X = -1, Y = -1;
            
            dfs(j,i,g[i][j]);
            clear();
            if(c != 1)continue;
            
            p.first.first = g[i][j], p.first.second = c2,p.second.first = X, p.second.second = Y;
            v.push_back(p);
         }
      }
      

      for(int i=0; i<v.size(); i++){
         cout << v[i].first.first << " " << v[i].first.second << endl;
         cout << v[i].second.first << " " << v[i].second.second << endl;
      }

      int ans = -1000;
      
      for(int i=0; i<n; i++){
         for(int j=0; j<i+1; j++){
            if(g[i][j] != 0)continue;
            int cnt = 0;
            for(int k=0; k<v.size(); k++){
               int x = v[k].second.first, y = v[k].second.second;
//               cout << "x = " << x << " y = " << y << endl;
//               cout << "j = " << j << " i = " << i << endl;
               if(x == j && y == i){
                  if(v[k].first.first == num) cnt -= v[k].first.second;
                  else cnt += v[k].first.second;
               }
            }
            
//            cout << "cnt = " << cnt << endl;
            ans = max(ans,cnt);
            
         }
      }
      cout << ans << endl;
   }
   return 0;
}
