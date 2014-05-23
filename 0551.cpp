#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

typedef pair<int,int> P;

int N,L;
int a[100001];

#define debug(x) cout << #x << " = " << x << endl;

bool isOk(int x){
   if(x == 0) return a[x] > a[x+1];
   if(x == N-1) return a[x] > a[x-1];
   return a[x-1] < a[x] && a[x+1] < a[x];
}

P getNext(int x){
   if(x < 0 || x >= N || !isOk(x)) return P(-1,-1);
   return P(a[x],x);
}

int main(){
   cin >> N >> L;
   for(int i=0; i<N; i++) cin >> a[i];

   int now = 0;
   priority_queue<P> que;
   for(int i=0; i<N; i++){
      if(isOk(i)) que.push(P(a[i],i));
   }
   
   while(!que.empty()){
      P p = que.top();
      que.pop();
      
      int plus = L - (p.first + now);
      
/*      debug(plus);
	debug(now);
	cout << "pos = " << p.second << endl;
*/
      
      if(plus > 0) now += plus;
      else plus = 0;

      a[p.second] = 0;
      P left = getNext(p.second-1);
      P right = getNext(p.second+1);
      
      if(left != P(-1,-1)){
	 left.first -= now;
	 que.push(left);
      }
      
      if(right != P(-1,-1)){
	 right.first -= now;
	 que.push(right);
      }
   }

   cout << now << endl;
   
   return 0;
}
