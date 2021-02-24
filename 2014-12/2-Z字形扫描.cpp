// 知识点: 模拟(分奇偶数行好做)
#include <iostream>
using namespace std;

const int N = 550;
int n;
int a[N][N];

int main(){
  cin >> n;

  for(int i = 1; i <= n; i++){
    for(int j = 1;j <= n; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 1; i <= 2 * n; i++){
    if(i % 2 == 0){
      for(int j = 1; j < i; j++){
        if(i - j < 1 || j < 1 || i - j > n || j > n) continue;
        cout << a[i - j][j] << " ";
      }
    }else{
      for(int j = 1; j < i; j++){
        if(i - j < 1 || j < 1 || i - j > n || j > n) continue;
        cout << a[j][i-j] << " ";
      }
    }
  }

  return 0;
}
