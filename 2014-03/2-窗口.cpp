// 知识点：数组，模拟
#include <iostream>
using namespace std;

int n,m,x,y;
const int N = 20;

struct windows{
int x1,y1,x2,y2,id;
}win[N];
int j;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> win[i].x1 >> win[i].y1 >> win[i].x2 >> win[i].y2;
    win[i].id = i + 1;
  }

  for(int i = 0; i < m; i++){
    cin >> x >> y;

    // 从顶层向后开始枚举
    for(j = n - 1; j >= 0; j--){
      windows w = win[j];
      if(x <= w.x2 && x >= w.x1 && y <= w.y2 && y >= w.y1){
        cout << w.id << endl;
        for(int k = j; k < n - 1; k++){
          win[k] = win[k + 1];
        }
        win[n-1] = w;
        break;
      }
    }
    if(j == -1){
      cout << "IGNORED" << endl;
    }

  }
  return 0;
}
