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
const int INF = 1<<29;
const double EPS = 1e-8;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

const int MAX = 50;

void mult(int m1[MAX][MAX], int m2[MAX][MAX], int n, int m){
   int res[MAX][MAX];
   fill(res[0],res[MAX],0);
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         for(int k=0; k<n; k++) res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % m;
      }
   }
   for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) m1[i][j] = res[i][j];
}

void mod_pow(int mat[MAX][MAX], int p, int n, int m){
  int res[MAX][MAX];
  fill(res[0], res[MAX], 0);
  for(int i=0;i<n;i++) res[i][i] = 1;
  while(p > 0){
    if(p & 1) mult(res, mat, n, m);
    mult(mat, mat, n, m);
    p >>= 1;
  }
  for(int i=0;i<n;i++)
     for(int j=0;j<n;j++) mat[i][j] = res[i][j];
}


int main(){
   int mat[MAX][MAX],tmp[MAX];
   int N,M,A,B,C,T;
   
   while(cin >> N >> M >> A >> B >> C >> T,N|M|A|B|C|T){

      for(int i=0; i<N; i++) cin >> tmp[i];
      fill(mat[0],mat[MAX],0);

      for(int i=0; i<N; i++){
         if(i-1 >= 0) mat[i][i-1] = C;
         mat[i][i] = B;
         if(i+1 < N) mat[i][i+1] = A;
      }

      mod_pow(mat,T,N,M);
      
      for(int i=0; i<N; i++){
         int ans = 0;
         for(int j=0; j<N; j++) ans = (ans + mat[j][i] * tmp[j]) % M;
         if(i == 0) cout << ans;
         else cout << " " << ans;
      }
      cout << endl;
      
   }
  return 0;
}
