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
const int MAX = 101;
const int INF = 1<<29;

using namespace std;

typedef string::const_iterator State;
typedef long long ll;
typedef pair<int,int> P;


int term(State &begin){
   
}
int number(State &begin){
   int res = 0;
   while(isdigit(*begin)){
      res *= 10;
      res += *begin;
      begin++;
   }
}

int main(){
   int n;
   cin >> n;
   cin.ignore();
   for(int i=0; i<n; i++){
      string s;
      getline(cin,s);
      State begin = s.begin();
   }
  return 0;
}
