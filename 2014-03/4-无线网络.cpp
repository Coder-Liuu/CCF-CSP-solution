// 求最短路径和具体的路径

#include <iostream>
using namespace std;

int n,m,k,r;
// n个无线路由器
// r距离之内可以直接相连
// m个可以额外放的位置
// k个可以增加的位置
const int N = 300;
struct point{
  int x,y;
}a[N];

int main(){
  cin >> n >> m >> k >> r;
  for(int i = 1; i <= n + m; i++){
    cin >> a[i].x >> a[i].y;
  }
  return 0;
}
