#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <cctype>
#include <math.h>

#define mp make_pair

//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

vector<string> v(8);

void change(int x, int y, bool flag){
    char moji[] = {'o','x'};

   for(int i=0; i<8; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8)continue;
      if(v[ny][nx] == '.' || v[ny][nx] == moji[flag])continue;
      bool flag2 = false;
      while(1){
         if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8)break;
         if(v[ny][nx] == moji[flag]){
            flag2 = true;
            break;
         } else if(v[ny][nx] == '.') break;
         
         ny += dy[i];
         nx += dx[i];
      }

      if(!flag2)continue;
      //yoko
      if(y == ny) for(int i=min(x,nx); i<=max(x,nx); i++) v[ny][i] = moji[flag];
      //tate
      else if(x == nx) for(int i=min(y,ny); i<=max(y,ny); i++) v[i][nx] = moji[flag];
      //naname
      else {
         v[y][x] = moji[flag];
         nx = x + dx[i], ny = y + dy[i];
         while(v[ny][nx] != moji[flag]){
            v[ny][nx] = moji[flag];
            ny += dy[i];
            nx += dx[i];
         }
      }
   } 
}

int f(int x, int y, bool flag){
   char moji[] = {'o','x'};
   int cnt = 0;

   for(int i=0; i<8; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8)continue;
      if(v[ny][nx] == '.' || v[ny][nx] == moji[flag])continue;
      bool flag2 = false;
      while(1){
         if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8)break;
         if(v[ny][nx] == moji[flag]){
            flag2 = true;
            break;
         } else if(v[ny][nx] == '.') break;
         
         ny += dy[i];
         nx += dx[i];
      }


      if(!flag2)continue;
      //yoko
      if(y == ny) cnt += abs(x-nx)-1;
      //tate
      else if(x == nx) cnt += abs(y-ny)-1;
      //naname
      else cnt += abs(x-nx)-1;      
      
   }

   return cnt;
}

void solve(){
   int pass = 0;
   bool flag = false;

   //false is Mami, true is Majo
   while(pass != 2){

      bool update = false;
      pair<pair<int,int>,int>p; //((x,y),cnt)
      p.second = 0;
      if(!flag){

         for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
               if(v[i][j] != '.')continue;
               int cnt = f(j,i,flag);
               
               if(p.second < cnt){
                  p.second = cnt;
                  p.first.first = j;
                  p.first.second = i;
               }
            }
         }

         if(p.second != 0){
            update = true;
            change(p.first.first,p.first.second,flag);
         }
         if(!update)pass++;
         else pass = 0;
         flag = 1 - flag;
      } else {
         
         for(int i=v.size()-1; i>=0; i--){
            for(int j=v[i].size()-1; j>=0; j--){
               if(v[i][j] != '.')continue;
               int cnt = f(j,i,flag);
               if(p.second < cnt){
                  p.second = cnt;
                  p.first.first = j;
                  p.first.second = i;
               }
            }
         }

         if(p.second != 0){
            update = true;
            change(p.first.first,p.first.second,flag);
         }
         if(!update)pass++;
         else pass = 0;
         flag = 1 - flag;
      }
   }
   
}

int main(){
   for(int i=0; i<8; i++) cin >> v[i];
   solve();
   for(int i=0; i<v.size(); i++) cout << v[i] << endl;

  return 0;
}
