#include <iostream>
#include <algorithm>
using namespace std;

int data[5];
char card[7][11] = {"one pair","two pair","three card","four card","full house",
		    "straight","null"};

void solve(){
  int count = 0,count3 = 0,count4 = 0,sum = 0;
  bool flag = false;
  
  sort(data,data+5);
  
  if(data[0] == data[1]-1 && data[1]-1 == data[2]-2 && data[2]-2 == data[3]-3
     && data[3]-3 == data[4]-4){
    cout << card[5] << endl;
    flag = true;
  }
  
  if(data[0] == 1 && data[1] == 10 && data[2] == 11 && data[3] == 12 &&
     data[4] == 13){
    cout << card[5] << endl;
    flag = true;
  }
  
  for(int i=0; i<5; i++){
    int count2 = 0;
    for(int j=i+1; j<5; j++){
      if(data[i] == data[j]){
	count++;
	count2++;
      }
    }
    if(count2 == 2)
      count3++;
    if(count2 == 3)
      count4++;
    if((count2 == 2 && count == 4) || (count2 == 1 && count == 4)){
      cout << card[4] << endl;
      flag = true;
    }
  }
  
  if(flag == false){
    if(count == 1){
      cout << card[0] << endl;
    }
    
    else if(count3 == 0 && count == 2){
      cout << card[1] << endl;
    }
    
    else if(count3 == 1 && count == 3){
      cout << card[2] << endl;
    }
    
    else if(count4 == 1 && count == 6){
      cout << card[3] << endl;
    }
    
    else if(count == 0){
      cout << card[6] << endl;
    }
  }
}
  int main(){
    char comma;
  while(cin >> data[0] >> comma >> data[1] >> comma >> data[2] >> comma >>
	data[3] >> comma >> data[4]){
    solve();
  }
  return 0;
} 
