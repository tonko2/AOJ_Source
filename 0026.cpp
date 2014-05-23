#include <cstdio>
#include <algorithm>

int main()
{
  int a[10][10] = {};
  int i,j,x,y,size,count=0,max;

  while(scanf("%d,%d,%d",&x,&y,&size) != EOF){
    if(size == 1){
      for(i=-1; i<=1; i++){
	if(y+i < 0 || y+i > 9)continue;
	else
	  a[x][y+i] += 1;
      }
      for(i=-1; i<=1; i++){
	if(x+i < 0 || x+i > 9)continue;
	else
	  a[x+i][y] += 1;
      }
      a[x][y] -= 1;
    }
    
    else if(size == 2){
      for(i=-1; i<=1; i++){
	for(j=-1; j<=1; j++){
	  if((x+i < 0  || y+j < 0) ||
	     (x+i >= 10 || y+j >= 10))
	    continue;
	  else
	    a[x+i][y+j] += 1;
	}
      }
    }
    else if(size == 3){
      for(i=-2; i<=2; i++){
	if(y+i < 0 || y+i >= 10)
	  continue;
	else
	  a[x][y+i] += 1;
      }

      for(i=-2; i<=2; i++){
	if(x+i < 0 || x+i >= 10)
	  continue;
	else
	  a[x+i][y] += 1; 
      }

      for(i=-1; i<=1; i+=2){
	for(j=-1; j<=1; j+=2){
	  if((x+i < 0  || y+j < 0) ||
	     (x+i >= 10 || y+j >= 10))
	    continue;
	  else
	    a[x+i][y+j] += 1;
	}
      }
      a[x][y] -= 1;
    }
    
    max = a[0][0];
    
    for(i=0; i<9; i++){
      for(j=0; j<9; j++){
	if(max < a[i][j])
	  max = a[i][j];
      }
    }
  }
  
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      if(a[i][j] == 0)
	count++;
    }
  }
  
  printf("%d\n",count);
  printf("%d\n",max);

  return 0;
}
