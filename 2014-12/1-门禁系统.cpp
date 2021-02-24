// 知识点: 数组模拟
#include <iostream>
using namespace std;

const int N = 1010;
int n;
int a[N];

int main(){
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    a[x]++;
    cout << a[x] << " ";
  }

  return 0;
}
