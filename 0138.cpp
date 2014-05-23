#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
  pair<double,int>p[8];
  pair<double,int>q[8];
  pair<double,int>r[8];
  pair<double,int>s[3];

  int a;
  double b;
  
  for(int i=0; i<8; i++){
    cin >> a >> b;
    p[i].first = b;
    p[i].second = a;
  }
  for(int i=0; i<8; i++){
    cin >> a >> b;
    q[i].first = b;
    q[i].second = a;
  }
  for(int i=0; i<8; i++){
    cin >> a >> b;
    r[i].first = b;
    r[i].second = a;
  }

  sort(p,p+8);
  sort(q,q+8);
  sort(r,r+8);


    s[0].first = p[2].first;
    s[0].second = p[2].second;
    s[1].first = q[2].first;
    s[1].second = q[2].second;
    s[2].first = r[2].first;
    s[2].second = r[2].second;

    sort(s,s+3);


  cout << fixed << setprecision(2);

  for(int i=0; i<2; i++)
    cout << p[i].second << ' ' << p[i].first << endl;
  for(int i=0; i<2; i++)
    cout << q[i].second << ' ' << q[i].first << endl;
  for(int i=0; i<2; i++)
    cout << r[i].second << ' ' << r[i].first << endl;
  for(int i=0; i<2; i++)
    cout << s[i].second << ' ' << s[i].first << endl;
  return 0;
} 

