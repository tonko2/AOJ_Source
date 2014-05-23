#include <iostream>
using namespace std;

int main(){
  char c[8][8],c2[8][8],c3[8][8];

  for(int i=0; i<8; i++) 
    cin >> c[i];

  cout << "90" << endl;
  for(int j=0; j<8; j++){
    for(int i=0; i<8; i++){
      cout << c[7-i][j];
      c2[j][i] = c[7-i][j];
    }
    cout << endl;
  }

  cout << "180" << endl;
  for(int j=0; j<8; j++){
    for(int i=0; i<8; i++){
      cout << c2[7-i][j];
      c3[j][i] = c2[7-i][j];
    }
    cout << endl;
  }

  cout << "270" << endl;
  for(int j=0; j<8; j++){
    for(int i=0; i<8; i++){
      cout << c3[7-i][j];
    }
    cout << endl;
  }
  return 0;
}
