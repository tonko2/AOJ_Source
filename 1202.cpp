#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
   int n;
   int tc = 1;
   while(cin >> n && n){
      vector<double>X,Y;
      double x1[1001],x2[1001],y1[1001],y2[1001];
      for(int i=0; i<n; i++){
         double x,y,r;
         cin >> x >> y >> r;
         X.push_back(x-r),X.push_back(x+r);
         Y.push_back(y-r),Y.push_back(y+r);
         x1[i] = x-r, x2[i] = x+r;
         y1[i] = y-r, y2[i] = y+r;
      }

      sort(X.begin(),X.end());
      sort(Y.begin(),Y.end());

      X.erase(unique(X.begin(),X.end()),X.end());
      Y.erase(unique(Y.begin(),Y.end()),Y.end());

      for(int i=0; i<n; i++){
         x1[i] = lower_bound(X.begin(),X.end(),x1[i])-X.begin();
         x2[i] = lower_bound(X.begin(),X.end(),x2[i])-X.begin();
         y1[i] = lower_bound(Y.begin(),Y.end(),y1[i])-Y.begin();
         y2[i] = lower_bound(Y.begin(),Y.end(),y2[i])-Y.begin();
      }

      int H = Y.size();
      int W = X.size();
      bool grid[1001][1001];
      fill(grid[0],grid[1001],false);
      
      for(int i=0; i<n; i++)
         for(int j=y1[i]; j<y2[i]; j++)
            for(int k=x1[i]; k<x2[i]; k++) grid[j][k] = true;


      double ans = 0;
      for(int i=0; i<H-1; i++){
         for(int j=0; j<W-1; j++){
            if(!grid[i][j])continue;
            ans += (X[j+1]-X[j]) * (Y[i+1]-Y[i]);
         }
      }
      printf("%d %.2f\n",tc++,ans);
   }
   return 0;
}
