#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool check(double a, double b, double c){
   return (a + b < c) || (a + c < b) || (b + c < a);
}

// a と x、b と y、c と z がそれぞれねじれの位置にある。
long double circumscribed_sphere(double a,double b,double c,double x,double y,double z){
#define sqr(x) ((x)*(x))
   double tv=sqr(a*x)*(sqr(b)+sqr(c)-sqr(a)+sqr(y)+sqr(z)-sqr(x))
      +sqr(b*y)*(sqr(c)+sqr(a)-sqr(b)+sqr(z)+sqr(x)-sqr(y))
      +sqr(c*z)*(sqr(a)+sqr(b)-sqr(c)+sqr(x)+sqr(y)-sqr(z))
      -sqr(a*y*z)-sqr(b*z*x)-sqr(c*x*y)-sqr(a*b*c);
   return sqrt(tv/144.0);
#undef sqr
}

int main(){
   int n;
   while(cin >> n,n){
      long double a[20];
      for(int i=0; i<n; i++) cin >> a[i];
      long double ans = 0;
      for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            if(i == j)continue;
            for(int k=0; k<n; k++){
               if(k == i || k == j)continue;
               if(check(a[i],a[j],a[k]))continue;
               for(int l=0; l<n; l++){
                  if(l == k || l == i || l == j)continue;
                  for(int m=0; m<n; m++){
                     if(check(a[j],a[l],a[m]))continue;
                     if(m == l || m == k || m == j || m == i)continue;
                     for(int o=0; o<n; o++){
                        if(check(a[i],a[l],a[o]))continue;
                        if(check(a[k],a[m],a[o]))continue;
                        if(o == m || o == l || o == k || o == j || o == i)continue;
                        ans = max(ans,circumscribed_sphere(a[i],a[j],a[k],a[m],a[o],a[l]));
                     }
                  }
               }
            }
         }
      }
      printf("%.6Lf\n",ans);
   }
   return 0;
}
