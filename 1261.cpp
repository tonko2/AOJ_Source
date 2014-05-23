#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

double r;
int s;
double ans;


struct node{
   double left,right,weight;
   node(){}
   node(double left, double right, double weight):left(left),right(right),weight(weight){}
};


void solve(vector<node> v){
   int n = v.size();
   if(n == 1){
      double width = v[0].left + v[0].right;
      if(r > width) ans = max(ans,width);
      return;
   }
   
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         if(i == j)continue;
         vector<node>tmp;
         node a = v[i];
         node b = v[j];
         node c;
         double sum = a.weight + b.weight;
         c.right = max(b.right + a.weight/sum, a.right - (b.weight/sum));
         c.left = max(a.left + b.weight/sum, b.left - (a.weight/sum));
         c.weight = sum;
         tmp.push_back(c);
         for(int k=0; k<n; k++){
            if(i == k || j == k)continue;
            tmp.push_back(v[k]);
         }
         solve(tmp);
      }
   }
}

int main(){
   int tc;
   cin >> tc;
   while(tc--){
      cin >> r >> s;
      vector<node>v(s);
      for(int i=0; i<s; i++) cin >> v[i].weight;
      ans = -1;
      solve(v);
      
      if(ans == -1) cout << -1 << endl;
      else printf("%.16f\n",ans);
   }
   return 0;
}
