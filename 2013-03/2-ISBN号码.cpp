// 知识点：字符串模拟

#include <iostream>
using namespace std;

const int MOD = 11;
int res,flag;
char out;
string s1;

int get(int x){
  return s1[x] - '0';
}
int main(){
  cin >> s1;
  res += get(0) * 1;

  res += get(2) * 2;
  res += get(3) * 3;
  res += get(4) * 4;

  res += get(6) * 5;
  res += get(7) * 6;
  res += get(8) * 7;
  res += get(9) * 8;
  res += get(10) * 9;

  if(res % MOD == 10) {
    if(get(12) == 'X' - '0') flag = 1;
    else flag = 0;
    out = 'X';
  }else {
    if(get(12) == res % MOD) flag = 1;
    else flag = 0;
    out = res % MOD + '0';
  }

  if(flag == 1) {
    cout << "Right" << endl;
  }else {
    for(int i = 0; i < 12; i++) {
      cout << s1[i];
    }
    cout << out;
  }
  return 0;
}
