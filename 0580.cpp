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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int main(){
   int N,K;
   while(cin >> N >> K){
      vector<int> X,Y,Z;
      vector<int> X1,X2,Y1,Y2,Z1,Z2;
      int field[101][101][101];
      memset(field,0,sizeof(field));
      for(int i=0; i<N; i++){
         int x1,x2,y1,y2,z1,z2;
         cin >> x1 >> y1 >> z1;
         cin >> x2 >> y2 >> z2;
         X1.push_back(x1);
         X2.push_back(x2);
         Y1.push_back(y1);
         Y2.push_back(y2);
         Z1.push_back(z1);
         Z2.push_back(z2);
         X.push_back(x1);
         X.push_back(x2);
         Y.push_back(y1);
         Y.push_back(y2);
         Z.push_back(z1);
         Z.push_back(z2);
      }

      sort(X.begin(),X.end());
      sort(Y.begin(),Y.end());
      sort(Z.begin(),Z.end());
      X.erase(unique(X.begin(),X.end()),X.end());
      Y.erase(unique(Y.begin(),Y.end()),Y.end());
      Z.erase(unique(Z.begin(),Z.end()),Z.end());


      for(int i=0; i<N; i++){
         X1[i] = find(X.begin(),X.end(),X1[i])-X.begin();
         X2[i] = find(X.begin(),X.end(),X2[i])-X.begin();
         
         Y1[i] = find(Y.begin(),Y.end(),Y1[i])-Y.begin();
         Y2[i] = find(Y.begin(),Y.end(),Y2[i])-Y.begin();

         Z1[i] = find(Z.begin(),Z.end(),Z1[i])-Z.begin();
         Z2[i] = find(Z.begin(),Z.end(),Z2[i])-Z.begin();
      }
      
      for(int i=0; i<N; i++){
         for(int x=X1[i]; x<X2[i]; x++)
            for(int y=Y1[i]; y<Y2[i]; y++)
               for(int z=Z1[i]; z<Z2[i]; z++)
                  field[x][y][z]++;
      }


      ll ans = 0;
      for(int i=0; i<N*2-1; i++)
         for(int j=0; j<N*2-1; j++)
            for(int k=0; k<N*2-1; k++)
               if(field[i][j][k] >= K)
                  ans += (ll)(X[i+1]-X[i])*(ll)(Y[j+1]-Y[j])*(ll)(Z[k+1]-Z[k]);
      
      cout << ans << endl;
   }
  return 0;
}
