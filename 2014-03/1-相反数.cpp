// 知识点：模拟

#include <iostream>
using namespace std;

int n,t,res;
int a[2020];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t;
    a[t+1000] = 1;
  }
  for(int i = 0; i <= 1000; i++){
    if(a[1000 - i] == 1 && a[ 1000 + i ] == 1)
      res++;
  }
  cout << res << endl;
  return 0;
}
