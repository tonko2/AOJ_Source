#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double PI = acos(-1);
int main(){
   double a,b,c;
   int cnt[4];
   fill(cnt,cnt+4,0);
   while(cin >> a >> b >> c){
      vector<double>v;
      v.push_back(a);
      v.push_back(b);
      v.push_back(c);
      sort(v.begin(),v.end());
      double sum = a+b+c;
      double remain = sum - v[2];
      if(v[2] >= remain) break;
      cnt[0]++;
      double maxAngle = 0;
      do{
         double A = v[0];
         double B = v[1];
         double C = v[2];
         double tmp = (B*B+C*C-A*A) / (2.0*B*C);
         maxAngle = max(maxAngle,acos(tmp));
      }while(next_permutation(v.begin(),v.end()));
      if(maxAngle < PI/2.0) cnt[2]++;
      else if(maxAngle > PI/2.0) cnt[3]++;
      else cnt[1]++;
   }
   for(int i=0; i<4; i++){
      if(i == 0) cout << cnt[i];
      else cout << " " << cnt[i];
      
   }
   
   cout << endl;

   return 0;
}
