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

#define mp make_pair

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,s,n) for(int i=(s); i<(int)(n); i++)
#define ALL(c) (c).begin(),(c).end()

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
   int n;
   while(cin >> n && n){
      cin.ignore();
      int table[24*3600+60*60+61];
      for(int i=0; i<24*3600+3600+61; i++) table[i] = 0;
      for(int i=0; i<n; i++){
         string str;
         getline(cin,str);
         stringstream ss(str);
         string strs[2];
         ss >> strs[0];
         ss >> strs[1];
         for(int k=0; k<2; k++){
            for(int j=0; j<strs[k].size(); j++){
               if(strs[k][j] == ':') strs[k][j] = ' ';
            }
         }

            for(int j=0; j<2; j++){
               stringstream ss2;
               ss2 << strs[j];
               int a,b,c;
               ss2 >> a, ss2 >> b, ss2 >> c;
               if(j == 0) table[3600*a+60*b+c]++;
               else table[3600*a+60*b+c]--;
            }
      }

      for(int i=0; i<90061; i++){
         if(i > 0) table[i] += table[i-1];
      }

      int ans = 0;
      for(int i=0; i<90061; i++) ans = max(ans,table[i]);
      cout << ans << endl;
   }
   return 0;
}
