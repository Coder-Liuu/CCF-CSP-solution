// 知识点: 模拟
#include <iostream>
using namespace std;

const int N = 10010;
int a[N];
int n;
int res;

int main(){

  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    a[x] = 1;
  }

  for(int i = 1; i < N - 1; i++){
    if(a[i] == 1 && a[i+1] == 1) 
      res++;
  }
  cout << res << endl;
  return 0;
}
