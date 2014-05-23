#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int> p, pair<int,int> p2){
   return p.second < p2.second;
}

int main(int argc, char *argv[])
{
   int n,m,h,k;
   while(cin >> n >> m >> h >> k,n|m|h|k){
      int point[1001],pos[1001];
      int value[1001];

      vector<pair<int,int> >data;
      for(int i=1; i<=n; i++){
         cin >> value[i];
         pos[i] = i;
      }
      for(int i=0; i<m; i++){
         pair<int,int> a;
         cin >> a.first >> a.second;
         data.push_back(a);
      }
      sort(data.begin(),data.end(),compare);

      vector<pair<int,int> >v;
      for(int i=0; i<data.size(); i++){
         int a,b;
         a = data[i].first, b = data[i].first+1;
         v.push_back(make_pair(pos[a],pos[b]));
         swap(pos[a],pos[b]);

      }
      
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      
      int value2[1001];
      for(int i=1; i<=n; i++)
         value2[pos[i]] = value[i];

      int sum = 0;
      for(int i=1; i<=k; i++) sum += value2[i];
      int ans = sum;
      int tmp = sum;
      for(int i=0; i<v.size(); i++){
         sum = tmp;
         int a = v[i].first,b = v[i].second;
         if(a > k && b > k) continue;
         if(a <= k && b <= k)continue;

         sum += a <= k ? -value2[a] : value2[a];
         sum += b <= k ? -value2[b] : value2[b];

         ans = min(ans,sum);
      }

      cout << ans << endl;
      
   }
   return 0;
}
