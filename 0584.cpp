#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;

int main(int argc, char *argv[]){
   int n;
   cin >> n;
   priority_queue<string>que[10];
   for(int i=0; i<n; i++){
      string str;
      cin >> str;
      int size = str.size();
      que[size].push(str);
      if(que[size].size() == 10) que[size].pop();
   }

   vector<string>v;
   for(int i=0; i<10; i++){
      while(!que[i].empty()){
         v.push_back(que[i].top());
         que[i].pop();
      }
   }

   priority_queue<ll>q;
   for(int i=0; i<v.size(); i++){
      for(int j=0; j<v.size(); j++){
         if(i == j)continue;
         string s = v[i] + v[j];
         q.push(atoll(s.c_str()));
         if(q.size() == 4) q.pop();
      }
   }
   
   cout << q.top() << endl;
   return 0;
}
