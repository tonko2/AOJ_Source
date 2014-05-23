#include <iostream>
using namespace std;

const int MAX = 20;
int problem[MAX][MAX];

int main(){
  int r,c;
  int ans = 0,count = 0;

  cin >> r >> c;

  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++) cin >> problem[i][j];

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(problem[i][j] == 1) count++;
    }
    ans = max(ans,count);
    count = 0;
  }

  cout << ans << endl;
  return 0;
}
