#include <iostream>
using namespace std;

int small[101][101],big[101][101];
int stu[101][101];
int main(){
  int n;
  while(cin >> n && n){
    fill(small[0],small[100],100000);
    fill(big[0],big[101],0);
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) cin >> stu[i][j];

    int smallest = 10000;
    int biggest = 0;
    int g,h;

    for(g=0; g<n; g++){
      for(h=0; h<n; h++){
	biggest = max(biggest,stu[h][g]);
	smallest = min(smallest,stu[g][h]);
      }
      small[g][0] = smallest;
      big[0][g] = biggest;
      smallest = 10000;
      biggest = 0;
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	small[i][j] = small[i][0];
	big[j][i] = big[0][i];
      }
    } 

    int res = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	if(small[i][j] == big[i][j]) res = small[i][j];
      }
    }
      cout << res << endl;
  }
  return 0;
}
