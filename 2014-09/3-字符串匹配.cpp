// 知识点: 字符串模拟
#include <iostream>
using namespace std;

string S1,S0;
int mode;
int n;


void lower(string & x){
  int len = x.length();
  for(int i = 0; i < len; i++){
    if(x[i] >= 'A' && x[i] <= 'Z'){
      x[i] += 32;
    }
  }
}

void solve(){
  string s1,t;
  string target;
  cin >> s1;
  t = s1;
  if(!mode){
    lower(s1);
    target = S0;
  }else{
    target = S1;
  }

  int res = s1.find(target);
  if(res != -1){
    cout << t << endl;
  }
}

int main(){
  cin >> S1 >> mode >> n;
  S0 = S1;
  lower(S0);
  
  while(n--){
    solve();
  }
  return 0;
}
