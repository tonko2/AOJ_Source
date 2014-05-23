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

const string moji[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
                       "ld","mb","mp","nc","nd","ng","nt","nw","ps","qu","cw","ts"};

int main(){
   int n;
   cin >> n;
   cin.ignore();
   vector<string>v;
   for(int tc=0; tc<n; tc++){
      string s,str;
      getline(cin,s);
      stringstream ss(s);
      while(ss >> str){
         v.push_back(str);
      }
   }


   int t[38][38];
   memset(t,0,sizeof(t));
   
   for(int i=0; i<v.size(); i++){
      string now = v[i];
      int pos = -1;

      while(now.size() != 0){
         for(int k=37; k>=0; k--){
            if(moji[k] == now.substr(0,moji[k].size())){
               bool flag = false;
               if(pos != -1){t[pos][k]++;flag = true;}
               pos = k;
               now = now.substr(moji[k].size(),now.size());
//               if(flag)pos = -1;
               break;
            }
         }
      }
   }
   for(int i=0; i<38; i++){
      int pos = 0;
      for(int j=0; j<38; j++){
         if(t[i][pos] < t[i][j]) pos = j;
      }
      cout << moji[i] << " " << moji[pos] << " " << t[i][pos] << endl;
   }
   

  return 0;
}
