#include <iostream>
#include <map>
#include <string>
using namespace std;

class State{
public:
   int start, end;
   string name;
};

int main(int argc, char *argv[])
{
   int n,q;
   while(cin >> n >> q,n|q){

      State data[n];
      for(int i=0; i<n; i++){
         string s;
         int a,b;
         cin >> s >> a >> b;
         data[i].start = b-a+1;
         data[i].name = s;
         data[i].end = b;
      }

      for(int i=0; i<q; i++){
         bool flag = false;
         int in;
         cin >> in;
         for(int j=0; j<n; j++){
            if(data[j].start <= in && data[j].end >= in){
               cout << data[j].name << " " << in-data[j].start+1 << endl;
               flag = true;
               break;
            }
         }
         if(!flag) cout << "Unknown" << endl;
      }
      
   }
   return 0;
}
