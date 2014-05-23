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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1<<29;
const int MAX = 1000050;


int n;
P dat[3*MAX];

//first = value , second = number
bool compare(pair<int,int> p, pair<int,int> p2){
   if(p.first == p2.first) return p.second > p2.second;
   return p.first < p2.first;
}

void init(int n_){
   n = 1;
   //簡単のため要素数を2のべき乗に
   while(n < n_) n*= 2;


   for(int i=0; i<2*n-1; i++) dat[i] = mp(0,0);
}


//k番目の値(0から)をaに変更
void update(int k, P a){
   //葉の節点
   k += n - 1;
   dat[k] = a;
   //登りながら更新
   while(k > 0){
      k = (k - 1) / 2;
      dat[k] = max(dat[k*2+1],dat[k*2+2],compare);
   }
}

//k番目の値を返す
P getValue(int k){
   return dat[k+n-1];
}


//[a,b)の最小値を求める
P query(int a, int b, int k, int l, int r){

   //[a,b)と[l,r)が交差しなければ INF
   if(r <= a || b <= l) return mp(-INF,-INF);


   //[a,b)が[l,r)を完全に含んでいれば、この節点の値
   if(a <= l && r <= b) return dat[k];


   P vl = query(a,b,k*2+1,l,(l+r)/2);
   P vr = query(a,b,k*2+2,(l+r)/2,r);
//   cout << "vl.first = " << vl.first << " vl.second = " << vl.second << endl;
//   cout << "vr.first = " << vr.first << " vr.second = " << vr.second << endl;
   return max(vl,vr,compare);
}




P _query(int a, int b){
   return query(a,b,0,0,n);
}

int main(){
   int q;
   cin >> n >> q;
   int N = n;
   init(n);
   for(int i=0; i<n; i++) update(i,mp(0,i));
   
   for(int i=0; i<q; i++){
      P p;
      cin >> p.first >> p.second;
      p.first--;
      P tmp = getValue(p.first);

      tmp.first += p.second;
      update(p.first,tmp);
      
      P ans;
      ans = _query(0,N);
      cout << ans.second+1 << " " << ans.first << endl;
   }


  return 0;
}
