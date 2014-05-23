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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> PP;
bool field[10][10];
int dx[] = {1,1,2,2,2,0,0,-1,-1,-2,-2,-2};
int dy[] = {2,-2,0,1,-1,2,-2,2,-2,0,1,-1};
int x,y,n,inx[10],iny[10];

int bfs(){
   queue<PP>que;
   int cnt = 0;
   que.push(PP(P(x,y),0));
   while(!que.empty()){
      PP p = que.front(); que.pop();
      if(p.second == n) return 1;

      memset(field,0,sizeof(field));
      for(int i=-1; i<=1; i++){
         for(int j=-1; j<=1; j++){
            int nx = inx[p.second] + i, ny = iny[p.second] + j;
            if(nx >= 0 && 10 > nx && ny >= 0 && 10 > ny){
               field[ny][nx] = 1;
            }
         }
      }

     
      for(int i=0; i<12; i++){
         int nx = p.first.first + dx[i], ny = p.first.second + dy[i];
         if(nx >= 0 && 10 > nx && ny >= 0 && 10 > ny && field[ny][nx] == 1){
            que.push(PP(P(nx,ny),p.second+1));
         }
      }      
      
   }
   return -1;
}

int main(){
   memset(field,0,sizeof(field));
   while(cin >> x >> y,x|y){
      cin >> n;
      for(int i=0; i<n; i++){
         cin >> inx[i] >> iny[i];
      }
      if(bfs() == -1) cout << "NA" << endl;
      else cout << "OK" << endl;
   }
  return 0;
}
