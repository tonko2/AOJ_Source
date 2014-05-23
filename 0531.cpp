#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define D(x) cout << #x << " = " << x << endl;
struct C{
   int x,y,x2,y2; //(x,y) -> hidarishita //(x2,y2) -> migiue
};


const int MAX = 4010;
bool used[MAX][MAX];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int W,H;

void dfs(int y, int x){
   used[y][x] = true;
   for(int i=0; i<4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= W || ny >= H || used[ny][nx])continue;
      dfs(ny,nx);
   }
}

int main(){
   while(cin >> W >> H,W|H){
      int n;
      cin >> n;
      C a[n];
      vector<int>vx;
      vector<int>vy;
      for(int i=0; i<n; i++){
         cin >> a[i].x >> a[i].y >> a[i].x2 >> a[i].y2;
         vx.push_back(a[i].x);
         vy.push_back(a[i].y);
         vx.push_back(a[i].x2);
         vy.push_back(a[i].y2);
      }

      vx.push_back(0),vy.push_back(0);
      vx.push_back(W),vy.push_back(H);
      
      sort(vx.begin(),vx.end());
      sort(vy.begin(),vy.end());
      vx.erase(unique(vx.begin(),vx.end()),vx.end());
      vy.erase(unique(vy.begin(),vy.end()),vy.end());

      map<int,int>mx,my;

      int x1[1001],x2[1001],y1[1001],y2[1001];

      for(int i=0; i<n; i++){
         x1[i] = lower_bound(vx.begin(),vx.end(),a[i].x)-vx.begin();
         x2[i] = lower_bound(vx.begin(),vx.end(),a[i].x2)-vx.begin();
         y1[i] = lower_bound(vy.begin(),vy.end(),a[i].y)-vy.begin();
         y2[i] = lower_bound(vy.begin(),vy.end(),a[i].y2)-vy.begin();
      }

      fill(used[0],used[MAX],false);

      H = vy.size();
      W = vx.size();

      for(int i=0; i<n; i++){
         int xx = x1[i];
         int xx2 = x2[i];
         int yy = y1[i];
         int yy2 = y2[i];
            
         for(int j=yy; j<yy2; j++)
            for(int k=xx; k<xx2; k++) used[j][k] = true;
      }

      H--,W--;
      
      int ans = 0;
      for(int i=0; i<H; i++){
         for(int j=0; j<W; j++){
            if(used[i][j])continue;
            ans++;
            dfs(i,j);
         }
      }
      cout << ans << endl;
   }
   return 0;
}


