#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000000000;

int sum[101][101];
int n;

void print(){
   for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
         cout << sum[i][j] << " ";
      }
      cout << endl;
   }
         
}
int main(int argc, char *argv[])
{

   int a[100][100];
   int ans = -INF;
   cin >> n;
   for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) cin >> a[i][j];

   for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++) sum[i][j] = a[i-1][j-1] + sum[i][j-1];

   print();
   
   for(int i=0; i<n; i++)
      for(int j=0; j<=n; j++) sum[i+1][j] += sum[i][j];


   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         for(int k=1; i+k<=n; k++){
            for(int l=1; j+l<=n; l++){
               ans = max(ans,
                         sum[i+k][j+l]-sum[i][j+l]-sum[i+k][j]+sum[i][j]);
            }
         }
      }
   }
   
   cout << ans << endl;
   return 0;
}
