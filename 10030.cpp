#include <iostream>
using namespace std;

const int MAX = 101;
int a[MAX][2],b[MAX][2],ans=0;

int main(){
  int n,m;

  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i][0];

  cin >> m;
  for(int i=0; i<m; i++)
    cin >> b[i][0];

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(a[i][0] == b[j][0] && b[j][1] == 0){
	ans++;
	b[j][1] = 1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
