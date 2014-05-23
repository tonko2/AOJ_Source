#include <iostream>
using namespace std;

int n,ans;
int a,b,c;
int data[3] = {200,300,500};

void dfs(int value, int cnt1, int cnt2, int cnt3){
  if(n == value){
    a = b = c = 0;
    if(cnt1/5){
      a = ((double)(cnt1/5*5*380))*0.8;
    }
      a += (cnt1%5)*380;
    if(cnt2/4){
      b = ((double)(cnt2/4*4*550))*0.85;
    }
      b += (cnt2%4)*550;
    if(cnt3/3){
      c = ((double)(cnt3/3*3*850))*0.88;
    }
      c += (cnt3%3)*850;
      int res = a + b + c;
    
    ans = min(ans,res);
  }
  if(value > n)return;

  for(int i=0; i<3; i++){
    int A,B,C;
    A = B = C = 0;
    if(i == 0)A = 1;
    else if(i == 1) B = 1;
    else C = 1;
    dfs(value+data[i],cnt1+A,cnt2+B,cnt3+C);
  }
}

int main(){
  while(cin >> n && n){
    ans = 1 << 21;
    dfs(0,0,0,0);
    cout << ans << endl;
  }
  return 0;
}
