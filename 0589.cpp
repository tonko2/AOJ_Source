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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

bool compare(string s, string s2){
   if(s.size() == s2.size()) return s < s2;
   else return s.size() < s2.size();
}
int main(){
   int n;
   cin >> n;
   map<string,int>m;
   vector<string>v;
   for(int i=0; i<n; i++){
      string str;
      int value;
      cin >> str >> value;
      if(m[str] == 0){
         v.push_back(str);
      }
      m[str] += value;


   }
   sort(v.begin(),v.end());
   sort(v.begin(),v.end(),compare);
   for(int i=0; i<v.size(); i++){
      cout << v[i] << " " << m[v[i]] << endl;
   }
   
  return 0;
}
