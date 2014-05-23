#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)n; i++)
const int MAX = 30;

class State{
public:
   char f[MAX][MAX];
   bool operator < (const State &s) const{
      return true;
   }
};

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char field[MAX][MAX];
char field2[MAX][MAX];

bool ok;
int h,w,n;
State t;
set<pair<int,int> >s,s2;
void copy(){
   REP(i,h)
      REP(j,w) t.f[i][j] = field[i][j];
}

State del(set<pair<int,int> > S, State tmp){
   set<pair<int,int> >::iterator it = S.begin();
   while(it != S.end()){
      tmp.f[it->first][it->second] = '.';
      it++;
   }
   return tmp;
}

bool func(State tmp){
   bool flag = true;
   REP(i,h){
      REP(j,w){
         if(tmp.f[i][j] != '.') flag = false;
         cout << tmp.f[i][j];
      }
      cout << endl;
   }
   return flag;
}

void dfs(int i, int j, State tmp, char c, int d){
   int nx = j + dx[d], ny = i + dy[d];
   if(nx >= 0 && w > nx && ny >= 0 && h > ny && tmp.f[ny][nx] == c){
      s.insert(make_pair(ny,nx));
      cout << "ny = " << ny << " nx = " << nx << endl;
      dfs(ny,nx,tmp,c,d);
   }
}

void bfs(){
   State tmp;   
   REP(i,h)
      REP(j,w) tmp.f[i][j] = field[i][j];
   
   queue<State>que;
   que.push(tmp);
   REP(i,h){
      REP(j,w){
         REP(k,2){
            int nx = j + dx[k], ny = i + dy[k];
            if(nx >= 0 && w > nx && ny >= 0 && h > ny &&
               field[i][j] != field[ny][nx] && field[i][j] != '.' &&
               field[ny][nx] != '.'){
               swap(field[i][j],field[ny][nx]);
               copy();
               que.push(t);
               swap(field[i][j],field[ny][nx]);
            }
         }
      }
   }

   while(!que.empty()){
      cout << "size = " << que.size() << endl;
      s2.clear();
      s.clear();
      if(ok)break;
      State p = que.front();
      que.pop();
      if(func(p));


      //     while(true){
         bool flag = false;

         REP(i,h){
            REP(j,w){
               if(p.f[i][j] == '.')continue;
               char c = p.f[i][j];
               cout << "i = " << i << "j = " << j << endl;
               REP(k,4){
                  s.insert(make_pair(i,j));
                  dfs(i,j,p,c,k);
                  if(s.size() >= n){
//                     cout << s.size() << endl;
                     set<pair<int,int> >::iterator it2 = s.begin();
                     while(it2 != s.end()){
                        //   cout << it2->first << " " << it2->second << endl;
                        it2++;
                     }
                     set<pair<int,int> >::iterator it = s.begin();
                     while(it != s.end()){
                        s2.insert(make_pair(it->first,it->second));
                        it++;
                     }
                     s.clear();
                     flag = true;
                  }
               }
            }
         }
//         return;
//         if(!flag)break;  
//      }
      p = del(s2,p);
      if(func(p)){
         ok = true;
         break;
      }
   }
}

int main(){
   while(cin >> h >> w >> n){
      ok = false;
      s2.clear();
      REP(i,h)
         REP(j,w) cin >> field[i][j];

      REP(i,h)
         REP(j,w) field2[i][j] = field[i][j];

      bfs();
      if(ok) cout << "YES" << endl;
      else cout << "NO" << endl;

   }
   return 0;
}
