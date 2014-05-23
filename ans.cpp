#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<cstdlib>
#include<deque>
#include<climits>
#include<cstring>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define INF 99999999
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;//cost to
typedef vector<string> VS;
typedef vector<string> VS;

const int MAX_N=150;
const int MAX_M=(MAX_N+1)/2;
const int MAX_K=10;
int N,M,WEIGHT,HEIGHT;
PI Lake[MAX_N][MAX_K];//Lake[y][x]
int dp[MAX_K][MAX_N][MAX_M];
int dfs(int x,int y,int m){
  int res=INT_MAX;
  if(y<HEIGHT){
    if(dp[x][y][m]>0) return dp[x][y][m];
    for(int nx=0;nx<=WEIGHT;nx++)
      if(Lake[y+1][nx].second>0)
	res=min(res,dfs(nx,y+1,m)+(Lake[y+1][nx].second+Lake[y][x].second)*abs(Lake[y+1][nx].first-Lake[y][x].first));
    if(m>=1){
      if(y+2>HEIGHT) return 0;
      for(int nx=0;nx<=WEIGHT;nx++)
	if(Lake[y+2][nx].second>0){
	res=min(res,dfs(nx,y+2,m-1)+(Lake[y+2][nx].second+Lake[y][x].second)*abs(Lake[y+2][nx].first-Lake[y][x].first));
	}
    }
    return dp[x][y][m]=res;
  }
  return 0;
}
int main(){
  WEIGHT=9;
  while(cin>>N>>M,(N||M)){
    memset(dp,0,sizeof(dp));
    memset(Lake,0,sizeof(Lake));
    HEIGHT=N-1;
    int y=0;
    REP(j,N){
      int k; cin>>k;      
      REP(i,k){
	int x,c;
	cin>>x>>c; 
	Lake[y][i]=make_pair(x,c);
      }
      y++;
    }
    int res=INT_MAX;
    for(int nx=0;nx<=WEIGHT;nx++)
      if(Lake[0][nx].second>0)
	res=min(res,dfs(nx,0,M));
    
    if(M>=1){
      for(int nx=0;nx<=WEIGHT;nx++)
	if(Lake[1][nx].second>0)
	  res=min(res,dfs(nx,1,M-1));
    }
    cout<<res<<endl;
  }
}
