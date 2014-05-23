#include <iostream>
using namespace std;

const int MAX = 10;

int main(){
  int n,dig[MAX][MAX][2],flag=0;

  cin >> n;
  for(int b=0; b<n; b++){
    if(flag)cout << endl;
    for(int i=0; i<9; i++)
      for(int j=0; j<9; j++)
	for(int k=0; k<2; k++) dig[i][j][k] = 0;

    for(int i=0; i<9; i++)
      for(int j=0; j<9; j++)cin >> dig[i][j][0];

    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
	for(int k=i; k<=i; k++){
	  for(int l=0; l<9; l++){
	    if((i == k && j != l) && (dig[i][j][0] == dig[k][l][0])){
	     
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
	  }
	}
      }
    }

    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
	for(int k=i; k<=i; k++){
	  for(int l=0; l<9; l++){
	    if(dig[j][i][0] == dig[l][k][0]){
	      if(i == k && j != l){
	      dig[j][i][1] = 1;
	      dig[l][k][1] = 1;
	      }
	    }
	  }
	}
      }
    }

    for(int i=0; i<3; i++)
      for(int j=0; j<3; j++)
	for(int k=0; k<3; k++)
	  for(int l=0; l<3; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
    for(int i=0; i<3; i++)
      for(int j=3; j<6; j++)
	for(int k=0; k<3; k++)
	  for(int l=3; l<6; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }

  
    for(int i=0; i<3; i++)
      for(int j=6; j<9; j++)
	for(int k=0; k<3; k++)
	  for(int l=6; l<9; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }

    for(int i=3; i<6; i++)
      for(int j=0; j<3; j++)
	for(int k=3; k<6; k++)
	  for(int l=0; l<3; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
    for(int i=3; i<6; i++)
      for(int j=3; j<6; j++)
	for(int k=3; k<6; k++)
	  for(int l=3; l<6; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
    for(int i=3; i<6; i++)
      for(int j=6; j<9; j++)
	for(int k=3; k<6; k++)
	  for(int l=6; l<9; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }

  
    for(int i=6; i<9; i++)
      for(int j=0; j<3; j++)
	for(int k=6; k<9; k++)
	  for(int l=0; l<3; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
    for(int i=6; i<9; i++)
      for(int j=3; j<6; j++)
	for(int k=6; k<9; k++)
	  for(int l=3; l<6; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
    for(int i=6; i<9; i++)
      for(int j=6; j<9; j++)
	for(int k=6; k<9; k++)
	  for(int l=6; l<9; l++)
	    if(i != k && j != l && dig[i][j][0] == dig[k][l][0]){
	      dig[i][j][1] = 1;
	      dig[k][l][1] = 1;
	    }
    
   



    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
	if(dig[i][j][1])
	  cout << '*' << dig[i][j][0];
	else
	  cout << ' ' << dig[i][j][0];
      }
      cout << endl;
      flag = 1;
    }
  }
  return 0;
}
