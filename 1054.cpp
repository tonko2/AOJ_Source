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

class data{
public:
   int lx,ly,rx,ry;
   string name;
};

int main(){
   int n,W,H;
   string s,now;
   while(cin >> n && n){
      map<string,vector<data> >m;
      deque<string>now;
      cin >> W >> H;
      for(int tc=0; tc<n; tc++){
         vector<data>v;
         int link;
         cin >> s >> link;
         if(tc == 0) now.push_back(s);
         for(int i=0; i<link; i++){
            data tmp;
            string name;
            cin >> tmp.lx >> tmp.ly >> tmp.rx >> tmp.ry >> tmp.name;
            v.push_back(tmp);
         }
         m[s] = v;
      }
      int loop;
      deque<string>prev;
      cin >> loop;
      for(int t=0; t<loop; t++){
         string order;
         cin >> order;
         if(order == "click"){
            int x,y;
            cin >> x >> y;
            vector<data> tmp = m[now.back()];
            for(int i=0; i<tmp.size(); i++){
               if(x >= tmp[i].lx && y >= tmp[i].ly &&
                  x <= tmp[i].rx && y <= tmp[i].ry){
                  now.push_back(tmp[i].name);
                  prev.clear();
                  break;
               }
            }
         } else if(order == "show") cout << now.back() << endl;
         else if(order == "back"){
            if(now.size() == 1) continue;
            prev.push_back(now.back());
            now.pop_back();
         } else if(order == "forward"){
            if(prev.size() == 0) continue;
            now.push_back(prev.back());
            prev.pop_back();
         }
      }
     
   }
   return 0;
}
