#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)
int main(){
   int n;
   while(cin >> n && n){
      string name[1001],order[1001],c[1001];
      int price[1001];

      rep(i,n) cin >> name[i] >> order[i] >> c[i] >> price[i];

      map<string,int>high;
      map<string,pair<pair<string,string> ,double> >low; //commodity, dealer,seller, price
      map<string,pair<int,double> >total; //commodity, <num,total_price>

      vector<string>v,v2;
      rep(i,n){
         v.push_back(name[i]);
         v2.push_back(c[i]);
      }

      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());

      sort(v2.begin(),v2.end());
      v2.erase(unique(v2.begin(),v2.end()),v2.end());

      
      bool used[1001];
      fill(used,used+1001,false);
      rep(i,n){
         if(order[i] == "SELL")continue;
         string A = name[i];
         string B = "";
         rep(j,n){
            if(c[i] != c[j])continue;
            if(name[i] == name[j])continue;
            if(i == j)continue;
            if(order[j] == "BUY")continue;
            if(used[j])continue;
            string B = name[j];
            double sum = price[i] + price[j];

            if(low.count(c[i])){
               if(low[c[i]].second > sum/2.0){
                  pair<pair<string,string>,int>p;
                  p.first.first = name[i];
                  p.first.second = name[j];
                  p.second = sum/2.0;
                  low[c[i]] = p;
               }
            } else {
               pair<pair<string,string>,int>p;
               p.first.first = name[i];
               p.first.second = name[j];
               p.second = sum/2.0;
               low[c[i]] = p;
            }

            if(high[c[i]] < sum/2.0){
               high[c[i]] = sum/2.0;
            }

            int cnt = total[c[i]].first;
            double t = total[c[i]].second;
            total[c[i]] = pair<int,int>(cnt+1,t+sum/2.0);
         }
      }


      

      rep(i,v2.size()){
         int l = low[v2[i]].second;
         int a = total[v2[i]].second / total[v2[i]].first;
         int h = high[v2[i]];

         cout << v2[i] << " " << l << " " << a << " " << h << endl;
      }


      rep(i,2) cout << "-";
      cout << endl;
      
      rep(i,10) cout << "-";
      cout << endl;
      
   }
   return 0;
}

