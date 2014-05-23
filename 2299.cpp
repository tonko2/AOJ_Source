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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//int dx[] = {0,1,1,1,0,-1,-1,-1};
//int dy[] = {1,1,0,-1,-1,-1,0,1};
const int MAX = 101;
const int INF = 1<<29;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int N,M;
   while(cin >> N >> M){
      char field[501][501];
      for(int i=0; i<N; i++)
         for(int j=0;j <M; j++) cin >> field[i][j];
      int ans = 0;
      while(true){
         bool update = false;
         for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
               if(field[i][j] != '.')continue;
               map<char,vector<pair<int,int> > >m;
               for(int k=0; k<4; k++){
                  int nx = j + dx[k], ny = i + dy[k];
                  while(1){
                     if(nx<0||nx>=M||ny<0||ny>=N)break;
                     if(field[ny][nx] != '.'){
                        m[field[ny][nx]].push_back(mp(ny,nx));
                        break;
                     }
                     nx += dx[k], ny += dy[k];
                  }  
               }
               map<char,vector<pair<int,int> > >::iterator it = m.begin();
               while(it != m.end()){
                  if(it->second.size() < 2){
                     it++;
                     continue;
                  }
                  update = true;
                  for(int c=0; c<it->second.size(); c++){
                     int x = it->second[c].second, y = it->second[c].first;
                     field[y][x] = '.';
                     ans++;
                  }
                  it++;
               }
            }
         }
         if(!update)break;
      }
      cout << ans << endl;
   }
  return 0;
}
