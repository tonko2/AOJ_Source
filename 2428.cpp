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

string strs = "01+-*()";
string s;
vector<string>v;
vector<int>pos;
int size;
bool used[101];
map<string,int>m;

int main(){

   while(cin >> s){
      v.clear();
      m.clear();
      pos.clear();
      for(int i=0; i<s.size(); i++){
         if(s[i] == '.') pos.push_back(i);
      }
      size = pos.size();
      sort(strs.begin(),strs.end());
      cout << strs << endl;
      do{
         v.push_back(strs);
      }while(next_permutation(strs.begin(),strs.end()));
      cout << v.size() << endl;
      
   }
   return 0;
}
