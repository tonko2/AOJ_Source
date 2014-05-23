#include <iostream>
#include <algorithm>
using namespace std;

int memo[10][10000];
int main(){
  int n,s,num[10],f[10],sum;
  for(int i=0; i<10; i++) num[i] = i;
  f[0] = 1;
  for(int i=1; i<10; i++) f[i] = f[i-1]*i;

  do{
    sum = 0;
    for(int i=0; i<10; i++){
      sum += (i+1)*num[i];
      memo[i][sum]++;
    }
  }while(next_permutation(num,num+10));

  while(cin >> n >> s){
    cout << memo[n-1][s] / f[10-n]<< endl;
  }
  return 0;
}
