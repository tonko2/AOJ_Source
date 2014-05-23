#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int>st;
  int n,a;

  while(cin >> n){
    if(n != 0)
      st.push(n);
    else{
      a = st.top();
      cout << a << endl;
      st.pop();
    }
  }
}
