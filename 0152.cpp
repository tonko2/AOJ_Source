#include <iostream>
#include <set>
using namespace std;

class Student{
public:
   int score,no;
   Student():score(0){}
   bool operator <(Student const &s) const{
      if(score != s.score){
         if(score > s.score) return true;
         else return false;
      } else {
         if(no < s.no) return true;
         else return false;
      }
   }
};
int main(){
   int n;
   while(cin >> n && n){
      set<Student>s;
      int data[9];
      for(int t=0; t<n; t++){
         Student tmp;
         cin >> tmp.no;
         for(int i=0; i<9; i++){
            data[i] = 0;
            int a,b;
            cin >> a;
            tmp.score += a;
            if(i-1 >= 0 && data[i-1] >= 1) tmp.score += a;
            if(i-2 >= 0 && data[i-2] == 2 && data[i-1] == 2) tmp.score += a;

            if(a == 10){
               data[i] = 2;
               continue;
            }

            cin >> b;
            tmp.score += b;
            if(i-1 >= 0 && data[i-1] == 2) tmp.score += b;
            if(a + b == 10) data[i] = 1;
               
         }
      
         int a,b,c;
         c = 0;
         cin >> a >> b;
         if(a + b >= 10) cin >> c;
         if(data[8] >= 1) tmp.score += a;
         if(data[7] == 2 && data[8] == 2) tmp.score += a;
         if(data[8] == 2) tmp.score += b;
         tmp.score += a + b + c;
         s.insert(tmp);
      
      }
      set<Student>::iterator it = s.begin();
      for(; it != s.end(); it++){
         cout << it->no << " " << it->score << endl;
      }
   }
   return 0;
}
