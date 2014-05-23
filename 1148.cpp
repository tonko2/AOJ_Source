#include <iostream>
#include <map>
#include <vector>
using namespace std;

class data{
public:
   int t,n,m,s;
};

const int MAX = 1001;
int main(){
   int n,m,r,q;
   while(cin >> n >> m,n|m){
      cin >> r;

      data array[MAX];
      for(int i=0; i<r; i++){
         cin >> array[i].t >> array[i].n >> array[i].m >> array[i].s;
      }
      cin >> q;
      int a,b,c;
      for(int i=0; i<q; i++){
         cin >> a >> b >> c;
         a -= 540;
         b -= 540;
         map<int,int>M;
         int ans = 0;
         bool time[721];
         fill(time,time+721,false);
         vector<pair<int,int> >v;
         for(int j=0; j<r; j++){
            if(c == array[j].m){
               if(array[j].s == 1){
                  M[array[j].n] = array[j].t;  
               } else {
                  v.push_back(make_pair(M[array[j].n]-540,array[j].t-540));
               }
            }
         }
         for(int j=0; j<v.size(); j++){
            for(int k=max(a,v[j].first); k<min(b,v[j].second); k++){
               time[k] = true;
            }
         }
         for(int j=0; j<721; j++){
            if(time[j])ans++;
         }
         cout << ans << endl;
      }
   }
   return 0;
}
