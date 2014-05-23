#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person{
   vector<int>next,rank;
   Person(){}
};


int main(){
   int N,M;
   while(cin >> N >> M,N|M){
      string dummy;
      getline(cin,dummy);

      Person a[N];
      map<string,int>m;
      map<int,string>m2;
      
      string in;
      int cnt = 0;
      int prev = 0;
      for(int i=0; i<N; i++){
         getline(cin,in);
         string name = "";
         for(int j=0; j<in.size(); j++){
            if(in[j] == ' ')cnt++;
            else name += in[j];
         }
         a[cnt].rank.push_back(i);
         m[name] = i;
         m2[i] = name;
         if(i){
            a[cnt-1].next.push_back(i);
         }
      }

      string X,ope,Y;
         while(M--){
            cin >> X >> dummy >> dummy >> ope >> dummy >> Y;
            if(ope == "child" || ope == "parend"){
               if(ope == "parent") swap(X,Y);
               int index1 = m[X], index2 = m[Y];
               for(int i=0; i<N; i++){
                  for(int j=0; j<a[i].rank.size(); j++){
                     if(index2 == a[i].rank[j])
                  }
               }




            
         }

         
      }

      cout << endl;
      
   }
   return 0;
}
