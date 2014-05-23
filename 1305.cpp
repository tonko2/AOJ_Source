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
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

map<string,vector<string> >m;
map<string,int>m2,used;

void dfs(string now){
   if(!m.count(now)) {m2[now] = 1; return;}

   vector<string>tmp = m[now];
   for(int i=0; i<tmp.size(); i++){
      if(used[tmp[i]])continue;
      dfs(tmp[i]);
      used[tmp[i]] = 1;
   }
}

int main(){
   int n;
   while(cin >> n,n){
      vector<vector<string> >v;
      string s;
      m.clear();
      m2.clear();
      used.clear();
      string start;
      for(int i=0; i<n; i++){
         cin >> s;
         for(int j=0; j<s.size(); j++){
            if(s[j] == ':' || s[j] == ',' || s[j] == '.') s[j] = ' ';
         }
         stringstream ss(s);
         string first,tmp;
         ss >> first;
         if(i == 0) start = first;
         vector<string>t;
         while(ss >> tmp){
            t.push_back(tmp);
         }
         m[first] = t;
      }

      string now = start;
      dfs(now);
      cout << m2.size() << endl;
      
   }
  return 0;
}
