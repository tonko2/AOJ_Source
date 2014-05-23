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
const int MAX = 52;
const int INF = 1<<29;

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int n,m,z,h;
int edge[MAX][MAX];
int edge2[220][220];
vector<P>v;


//行列の掛け算
vector<int> calc(const vector<int>& a, const vector<int>& b){
   vector<int> ret;
   for(int i=0; i<h; i++){
      for(int j=0; j<h; j++){
         int sum = 0;
         for(int k=0; k<h; k++){
            sum |= a[i*h+k] * b[k*h+j];
         }
         ret.push_back(sum);
      }
   }
   return ret;
}


//繰り返し２乗法
vector<int> multi(vector<int>& matrix, int k){
   if(k == 1) return matrix;

   vector<int> tmp = multi(matrix,k/2);
   if(k % 2){
      // 行列 * (行列*行列)という繰り返し２乗法
      return calc(matrix,calc(tmp,tmp));
   } else {
      // 繰り返し２乗法
      return calc(tmp,tmp);
   }
}
int main(){


   while(cin >> n >> m >> z,n|m|z){
      fill(edge[0],edge[MAX],0);
      fill(edge2[0],edge2[220],0);

      v.clear();
      for(int i=0; i<m; i++){
         int f,t;
         cin >> f >> t;
         edge[f][t] = edge[t][f] = 1;
      }

      //(0,0)も追加
      edge[1][1] = 1;

      
      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            if(edge[j][i] == 1) v.push_back(mp(i-1,j-1));               
         }
      }

      
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            if(v[i].first != v[j].first &&
               v[i].first == v[j].second && v[i].second != v[j].first){
               edge2[i][j] = 1;
            }
         }
      }

      h = v.size();
      vector<int>mat;
      
      for(int i=0; i<v.size(); i++){
         for(int j=0; j<v.size(); j++){
            mat.push_back(edge2[i][j]);
         }
      }
      vector<int> hoge = multi(mat,z);

      bool f = false;

      for(int i=0; i<v.size(); i++){
         if(v[i].first == n-1 && hoge[i]){
               f = true;
               break;
         }
      }
      if(f) cout << "yes" << endl;
      else cout << "no" << endl;
   }
  return 0;
}
