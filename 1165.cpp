#include <iostream>
using namespace std;

const int MAX = 200;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
  int N,n,d,maxx,maxy,minx,miny,Point[MAX][2];
  while(cin >> N && N){
    maxx = maxy = minx = miny = Point[0][0] = Point[0][1] = 0;
    for(int i=1; i<N; i++){
      cin >> n >> d;
      Point[i][0] = Point[n][0] + dx[d];
      Point[i][1] = Point[n][1] + dy[d];
      maxx = max(maxx,Point[i][0]);
      maxy = max(maxy,Point[i][1]);
      minx = min(minx,Point[i][0]);
      miny = min(miny,Point[i][1]);
    }
    cout << maxx-minx+1 << " " << maxy-miny+1 << endl;
  }
  return 0;
}
