#include <iostream>
using namespace std;

const int MAX_S = 100000;
const int MAX_B = 1000;

int s[MAX_S],b[MAX_B][MAX_B];

int main(){
  int n,k,count,sum;

  while(cin >> n >> k && (n || k)){
    count = 0;
    for(int i=0; i<k; i++)cin >> s[i];
    
    for(int i=0; i<n; i++)
      for(int j=0; j<k; j++) cin >> b[i][j];
    
    for(int i=0; i<k; i++){
      sum = 0;
      for(int j=0; j<n; j++){
	sum += b[j][i];
      }
      if(s[i] >= sum)
	count++;
    }

    if(count == k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
