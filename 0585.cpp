#include <iostream>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

const double PI = acos(-1);
const int EPS = 1e-7;
bool compare(complex<double>c1, complex<double>c2){
   if(fabs(c1.real()-c2.real()) < EPS){
      return c1.imag() < c2.imag();
   } else {
      return c1.real() < c2.real();
   }
}

int main(int argc, char *argv[]){
   srand(time(NULL));
   int a = rand() % 180 + 1;
   double angle = a * PI / 180.0;
   int n;
   cin >> n;
   vector<complex<double> >v;
   for(int i=0; i<n; i++){
      complex<double>p;
      cin >> p.real() >> p.imag();
      double tmpx = p.real();
      double tmpy = p.imag();
      p.real() = cos(angle)*tmpx + sin(angle)*tmpy;
      p.imag() = -sin(angle)*tmpx + cos(angle)*tmpy;
      v.push_back(p);
   }

   sort(v.begin(),v.end(),compare);
   
   double ans = 1e+7;
   for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
         if(fabs(v[i].real() - v[j].real()) > ans) break;
         double dis = sqrt(pow(v[i].real()-v[j].real(),2) +
                           pow(v[i].imag()-v[j].imag(),2));
         ans = min(ans,dis);  
      }
   }
   cout << ans*ans << endl;
   return 0;
}
