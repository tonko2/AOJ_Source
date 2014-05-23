#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

double BMI;
int main()
{

  long long int n,shi,ta,a,num;
 
  while(cin >> n,n){
    pair<double,long long int>pa[n];
    for(int i=0; i<n; i++){
      cin >> num >> shi >> ta;
      BMI = (double)(ta*10000) / (double)(shi*shi);
      BMI -= 22;
      if(BMI < 0){
	BMI *= -1;
      }
      //     cout << "BMI " << BMI << endl; 
      pa[i].first = BMI;
      pa[i].second = num;
    }
    sort(pa,pa+n);
 
    cout << pa[0].second << endl;
  }
  return 0;
}
