#include <iostream>
#include <cstdio>
using namespace std;

const int dx[] = {1,0};
const int dy[] = {0,1};
const int dx2[] = {-1,1};
const int dy2[] = {1,-1};

int main(){
  int n,data[11][11],cnt=0;
  while(1){
    scanf("%d",&n);
    if(n == 0)break;
    int num=2,nowx,nowy;
    bool flag = false,flag2 = false;
    nowx = nowy = 0;
    data[nowy][nowx] = 1;
    while(num != n*n+1){
      if(!flag){
	if(nowx == n-1)goto end;
	nowx += dx[0];
	nowy += dy[0];
	data[nowy][nowx] = num++;
	flag = true;
      }
      else{
      end:;
	if(nowy == n-1){
	  nowx += dx[0];
	  nowy += dy[0];
	  data[nowy][nowx] = num++;
	  flag = false;
	}
	else{
	  nowx += dx[1];
	  nowy += dy[1];
	  data[nowy][nowx] = num++;
	  flag = false;
	}
      }
      
      
      if(num == n*n+1)break;
      if(!flag2){
	while(1){
	  if(nowx == 0 || nowy == n-1){
	    flag2 = true;
	    break;
	  }
	  nowx += dx2[flag2];
	  nowy += dy2[flag2];
	  data[nowy][nowx] = num++;
	}
      }
      else{
	while(1){
	  if(nowx == n-1 || nowy == 0){
	    flag2 = false;
	    break;
	  }
	  nowx += dx2[flag2];
	  nowy += dy2[flag2];
	  data[nowy][nowx] = num++;
	}
      }
    }
    printf("Case %d:\n",++cnt);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	printf("%3d",data[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}

  
