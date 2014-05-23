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

int main(){
   char c;
   map<char,int>m;

   for(int i=2; i<10; i++) m['0'+i] = i;
   m['T'] = 10;
   m['J'] = 11;
   m['Q'] = 12;
   m['K'] = 13;
   m['A'] = 14;
   
   while(cin >> c){
      if(c == '#')break;
      vector<vector<string> >v;
      v.resize(4,vector<string>(13));
      for(int i=0; i<4; i++)
         for(int j=0; j<13; j++) cin >> v[i][j];

      
      int now = 0;


      int win[2];
      win[0] = win[1] = 0;
      for(int j=0; j<13; j++){
         char nowMark = v[now][j][1];
         int value = 0;
         bool flag = false;
         for(int i=0; i<4; i++){
            int C = m[v[i][j][0]];
            if(flag){
               if(v[i][j][1] == c && value < C){
                  now = i;
                  value = C;
               }
            } else {
               if(v[i][j][1] == c){
                  now = i;
                  value = C;
                  flag = true;
               } else if(v[i][j][1] == nowMark && value < C){
                  now = i;
                  value = C;
               }
            }
         }
         win[now%2]++;
      }
      if(win[0] > win[1]) cout << "NS " << win[0]-6 << endl;
      else cout << "EW " << win[1]-6 << endl;
   }
   

  return 0;
}
