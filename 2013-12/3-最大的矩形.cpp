// 知识点：枚举

#include <iostream>
#include <stack>

using namespace std;
stack<int> s;

int n;
const int N = 1010;
int a[N];
int res;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    int mmin = a[i];
    int area = 0;
    for(int j = i; j <= n; j++) {
      if(a[j] < mmin) mmin = a[j];
      area = max(area,mmin * (j - i + 1));
    }
    if(area > res) res = area;
  }

  cout << res << endl;
  return 0;
}
