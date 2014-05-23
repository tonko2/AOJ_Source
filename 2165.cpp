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
const int M = 256;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool equal(double a, double b){return fabs(a-b) < EPS;}
bool isPrime(ll a){for(ll i=2; i*i<=a; i++) if(a%i == 0) return false; return true;}
string toStr(int a){ostringstream oss;oss << a;return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int I[300],R[300],O[300];
int main(){
   int N;
   while(cin >> N,N){
    
      for(int i=0; i<N; i++) cin >> I[i];

      int ansS,ansA,ansC;
      double H = 1<<29;
      for(int S=0; S<=15; S++){
         for(int A=0; A<=15; A++){
            for(int C=0; C<=15; C++){
               R[0] = S;
               for(int i=1; i<N; i++){
                  R[i] = (A*R[i-1]+C) % M;
               }

               map<int,int>m;
               for(int i=0; i<N; i++){
                  O[i] = (I[i] + R[i]) % M;
                  m[O[i]]++;
               }

               double tmpH = 0;
               map<int,int>::iterator it = m.begin();
               while(it != m.end()){
                  tmpH += (it->second/(double)N) *
                     log(it->second/(double)N);
                  it++;
               }
               tmpH *= -1;

               if(H > tmpH){
                  H = tmpH;
                  ansS = S;
                  ansA = A;
                  ansC = C;
               }
            }
         }
      }
      cout << ansS << " " << ansA << " " << ansC << endl;
   }
   return 0;
}
