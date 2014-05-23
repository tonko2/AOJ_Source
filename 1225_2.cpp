#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)

int main(){
   int n;
   while(cin >> n && n){
      string name[1001],order[1001],c[1001];
      int price[1001];

      rep(i,n) cin >> name[i] >> order[i] >> c[i] >> price[i];

      map<string,int>low,high;
      map<string,pair<int,int> >total;
      vector<string>v,v2;

      map<string,pair<int,int> >m;
      
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
      
      while(true){
         bool flag = false;
         
         for(int i=n-1; i>=0; i--){
            if(order[i] == "BUY" && !used[i]) flag = true;
         }

         if(!flag)break;
         for(int i=n-1; i>=0; i--){
            if(order[i] == "SELL")continue;
            
            string A = name[i];
            string B = "";
            int value = 1<<29;
            int index = 0;
            
            int I = i;
            for(int j=I; j>=0; j--){
               if(used[j])continue;
               if(order[j] == "BUY" && c[i] == c[j] && price[i] > price[j]){
                  i = j; A = name[i];
               }
            }
            
            used[i] = true;
            
            for(int j=n-1; j>=0; j--){
               if(c[i] != c[j])continue;
               if(name[i] == name[j])continue;
               if(i == j)continue;
               if(order[j] == "BUY")continue;
               if(used[j])continue;
            
               int sum = price[i] + price[j];
               if(value > sum/2){
                  value = sum/2;
                  B = name[j];
                  index = j;
               }
            
            }
            
            if(B == "")continue;
            used[index] = true;
            if(low.count(c[i]) == 0 || low[c[i]] > value) low[c[i]] = value;
            if(high[c[i]] < value) high[c[i]] = value;
            int T = total[c[i]].second;
            int S = total[c[i]].first;
            total[c[i]] = pair<int,int>(S+value,T+1);

            int left = m[A].first;
            int right = m[A].second;
         
            int left2 = m[B].first;
            int right2 = m[B].second;

            m[A] = pair<int,int>(left+value,right);
            m[B] = pair<int,int>(left2,right2+value);
         
         }
      }
      
      rep(i,v2.size()){
         int l = low[v2[i]];
         int a = 0;
         if(total[v2[i]].second != 0) 
            a = total[v2[i]].first / total[v2[i]].second;
         int h = high[v2[i]];
         if(l == 0 && a == 0 && h == 0)continue;
         cout << v2[i] << " " << l << " " << a << " " << h << endl;
      }

      rep(i,2) cout << "-";
      cout << endl;


      rep(i,v.size()){
         cout << v[i] << " " << m[v[i]].first << " " << m[v[i]].second << endl;
      }
      
      
      rep(i,10) cout << "-";
      cout << endl;
      
   }
   return 0;
}

