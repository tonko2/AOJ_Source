#include <iostream>
using namespace std;

const int MAX = 1100;
int sum_J[MAX][MAX],sum_O[MAX][MAX],sum_I[MAX][MAX];
char moji[MAX][MAX];

int main(){
  int m,n,k;

  cin >> m >> n >> k;
  for(int i=1; i<=m; i++)
    for(int j=1; j<=n; j++) cin >> moji[i][j];

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
	sum_J[i][j] = sum_J[i][j-1]+sum_J[i-1][j]-sum_J[i-1][j-1];
	sum_O[i][j] = sum_O[i][j-1]+sum_O[i-1][j]-sum_O[i-1][j-1];
	sum_I[i][j] = sum_I[i][j-1]+sum_I[i-1][j]-sum_I[i-1][j-1];
	
	if(moji[i][j] == 'J') sum_J[i][j]++;
	else if(moji[i][j] == 'O') sum_O[i][j]++;
	else sum_I[i][j]++;
    }
  }
  
  for(int i=0; i<k; i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sum_J[x2][y2]-sum_J[x1-1][y2]-sum_J[x2][y1-1]+sum_J[x1-1][y1-1]
	 << ' ' << 
      sum_O[x2][y2]-sum_O[x1-1][y2]-sum_O[x2][y1-1]+sum_O[x1-1][y1-1]
	 << ' ' << 
      sum_I[x2][y2]-sum_I[x1-1][y2]-sum_I[x2][y1-1]+sum_I[x1-1][y1-1] << endl;
  }
  return 0;
}
