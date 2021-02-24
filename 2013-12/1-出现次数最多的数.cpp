// 知识点：哈希表

#include <iostream>
using namespace std;

int n,t;
const int N = 1100;
int a[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> t;
    a[t]++;
  }

  int mmax = 0;
  int mmint = 0;
  for(int i = 0; i < N; i++) {
    if(a[i] > mmax) {
      mmax = a[i];
      mmint = i;
    }
  }
  cout << mmint << endl;
  return 0;
}
