#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lli;
int main(){
  vector<int>car,total2;
  int num2[8];
  lli ans = 100000,total;
  while(cin >> num2[0] >> num2[1] >> num2[2] >> num2[3] >> num2[4] >> num2[5] >>
	num2[6] >> num2[7]){
    car.clear();
    total2.clear();
    car.push_back(4);
    car.push_back(1);
    car.push_back(4);
    car.push_back(1);
    car.push_back(2);
    car.push_back(1);
    car.push_back(2);
    car.push_back(1);
    ans = 100000;
   
    vector<int>::iterator it;
    int cnt2,counting = 1;
    for(int i=0; i<8; i++){
      rotate(car.begin(),car.begin()+counting,car.end());
      total = 0;
      cnt2 = 0;
      for(it = car.begin(); it != car.end(); it++){
	int tmp2 = num2[cnt2++] - *it; 
	if(tmp2 < 0)tmp2 = 0;
	total += tmp2;
	//	cout << *it;
      }
      //      cout << endl;
      ans = min(ans,total);
      total2.push_back(total);
    }
    
    car.clear();
    car.push_back(4);
    car.push_back(1);
    car.push_back(4);
    car.push_back(1);
    car.push_back(2);
    car.push_back(1);
    car.push_back(2);
    car.push_back(1);

    int cnt;
    string res;

    for(int i=0; i<8; i++){
      rotate(car.begin(),car.begin()+counting,car.end());
      total = 0;
      cnt2 = 0;
      res = "";
      for(it = car.begin(); it != car.end(); it++){
	int tmp2 = num2[cnt2++] - *it; 
	if(tmp2 < 0)tmp2 = 0;
	total += tmp2;
	res += (*it) + '0';
      }
      if(total == ans){
	goto end;
      }
    }
  end:;
    cout << res[0];
    for(int i=1; i<res.size(); i++)
      cout << ' ' << res[i];
    cout << endl; 
  }
}
