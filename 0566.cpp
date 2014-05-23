#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 101;


int main(){
  int n;
  cin >> n;
  vector<pair<int,int> >v(n); 
  vector<int>v2(n);
  vector<int> p(n,0);
 
  for(int i=0; i<n*(n-1)/2; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(c > d) p[a-1] += 3;
    else if(c < d) p[b-1] += 3;
    else{
      p[a-1] += 1, p[b-1] += 1;
    }
  }

  for(int i=0; i<p.size(); i++){
    v[i].first = p[i];
    v[i].second = i;
  }

  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());


  for(int i=0; i<v2.size(); i++){
    v2[v[i].second] = i + 1;
    if(i > 0 && v[i-1].first == v[i].first){
      v2[v[i].second] = v2[v[i-1].second];
    }
  }

  for(int i=0; i<v2.size(); i++) cout << v2[i] << endl;

  return 0;
} 
