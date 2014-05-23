#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int n,a[100][100];

  while(cin >> n,n){
    int sum[100][100] ={},sum2[100][100] = {};
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	cin >> a[i][j];
	sum[i][n] += a[i][j];
      }
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	sum2[n][i] += a[j][i];
      }
    }

    for(int i=0; i<n; i++)
      sum2[n][n] += sum[i][n];

    cout << right << setw(5);

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	cout << right << setw(5) << a[i][j];
      }
      cout << right << setw(5) << sum[i][n] << endl;
    }
    int k;
    for(k=0; k<n; k++)
      cout << right << setw(5) << sum2[n][k];
    cout <<  right << setw(5) << sum2[n][k] << endl;

  }
  return 0;
}
