#include <iostream>
using namespace std;

const int MAX = 1441;
bool flag[MAX];
int gettime(int time){
   return (time / 100) * 60 + time % 100;
}
int main(){
   int n,a,b;
   while(cin >> n >> a >> b,n|a,b){
      fill(flag,flag+1441,false);
      for(int tc=0; tc<n; tc++){
         int loop,start,finish;
         start = gettime(a);
         cin >> loop;
         for(int i=0; i<loop; i++){
            int in,in2;
            cin >> in >> in2;
            finish = gettime(in);
            for(int j=start; j<finish; j++) flag[j] = true;
            start = gettime(in2);
         }
         finish = gettime(b);
         for(int i=start; i<finish; i++) flag[i] = true;
         
      }
      int max_i = 0, cnt = 0;
      for(int i=0; i<MAX; i++){
         if(flag[i]) cnt++;
         else max_i = max(max_i,cnt),cnt = 0;
      }
      cout << max_i << endl;
   }
   return 0;
}
