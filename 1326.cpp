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

int main(){
   int p,q;
   while(cin >> p >> q,p|q){
      int indent[20];
      fill(indent,indent+20,0);
      vector<string>v,v2;
      vector<pair<int,pair<int,int> > >v3;
      for(int i=0; i<p; i++){
         string s;
         cin >> s;
         v.push_back(s);
         for(int j=0; j<s.size(); j++){
            if(s[j] == '.') indent[i]++;
            else break;
         }
      }

      for(int j=0; j<q; j++){
         string s;
         cin >> s;
         v2.push_back(s);
      }

//      for(int i=0; i<p; i++) cout << "indent = " << indent[i] << endl;
      

      
      int R = 0,C = 0,S = 0;
      int Ro = 0, Rc = 0, Co = 0, Cc = 0, So = 0, Sc = 0;
      bool flag;
      for(int r=1; r<=20; r++){
         R = r;
         for(int c=1; c<=20; c++){
            C = c;
            for(int s=1; s<=20; s++){
               Ro = 0, Rc = 0, Co = 0, Cc = 0, So = 0, Sc = 0;
               S = s;
               flag = false;
               for(int i=0; i<v.size()-1; i++){
                  for(int j=0; j<v[i].size(); j++){
                     if(v[i][j] == '(') Ro++;
                     if(v[i][j] == ')') Rc++;
                     if(v[i][j] == '{') Co++;
                     if(v[i][j] == '}') Cc++;
                     if(v[i][j] == '[') So++;
                     if(v[i][j] == ']') Sc++;
                  }
                  int value = R*(Ro-Rc) + C*(Co-Cc) + S*(So-Sc);
                  if(value != indent[i+1]){flag = true; break;}
               }
               pair<int,pair<int,int> >pp;
               pp.first = R;
               pp.second.first = C;
               pp.second.second = S;
               if(!flag) v3.push_back(pp);
            }
         }
      }



      
      Ro = 0, Rc = 0, Co = 0, Cc = 0, So = 0, Sc = 0;      
      for(int i=0; i<v2.size(); i++){
         if(i == 0) cout << 0;
         else {
            int value = -1;
            bool flag = false;
            for(int j=0; j<v2[i-1].size(); j++){
               value = -1;
               if(v2[i-1][j] == '(') Ro++;
               if(v2[i-1][j] == ')') Rc++;
               if(v2[i-1][j] == '{') Co++;
               if(v2[i-1][j] == '}') Cc++;
               if(v2[i-1][j] == '[') So++;
               if(v2[i-1][j] == ']') Sc++;
            }
            for(int t=0; t<v3.size(); t++){
               R = v3[t].first;
               C = v3[t].second.first;
               S = v3[t].second.second;
               int value2 = R*(Ro-Rc) + C*(Co-Cc) + S*(So-Sc);
               if(value == -1) value = value2;
               else if(value2 != value) {flag = true; break;}
            }
            
            if(flag) cout << " " << -1;
            else cout << " " << value;
         }
      }
      cout << endl;
   }
   return 0;
}
