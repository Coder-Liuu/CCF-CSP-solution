// 知识点: 模拟
#include <iostream>
#include <map>
#include <utility>
using namespace std;

char c[60];
bool b[60];
string s[100];
int len;
int tail = 0;

map<string,string> mm;

int check(char a){
  for(int i = 0; i < tail; i++){
    if(a == c[i] && b[i] == 0) return 0;
    if(a == c[i] && b[i] == 1) return 1;
  }
  return -1;
}

int main(){
  string cmd;
  cin >> cmd;

  // 预处理
  len = cmd.length();
  for(int i = 0; i < len; i++){
    if(cmd[i] != ':' && i + 1 < len && cmd[i+1] == ':'){
      c[tail] = cmd[i];
      b[tail++] = 1;
    }else if(cmd[i] != ':'){
      c[tail++] = cmd[i];
    }
  }


  int n;
  string s1;
  cin >> n;
  getchar();

  for(int ll = 1; ll <= n; ll++){
    getline(cin,s1);
    // 切割字符串
    int tail2 = 0;
    string s2 = "";
    len = s1.length();
    for(int i = 0; i < len; i++){
      if(s1[i] != ' ') s2+=s1[i];
      else{
        s[tail2++] = s2;
        s2 = "";
      }
    }
    s[tail2++] = s2;
    
    // 分情况讨论
    for(int i = 1; i < tail2; i++){
      if(s[i][0] != '-') break;
      int res = check(s[i][1]);
      if(res == -1) break;
      if(res == 0){
        mm[s[i]] = "";
      }
      if(res == 1){
        if(i + 1 >= tail2) break;
        mm[s[i]] = s[i+1];
        i++;
      }
    }

    // 输出结果
    cout << "Case " << ll << ": ";
    for(auto x: mm){
      cout << x.first;
      if(x.second == "") cout << " ";
      else cout << " " << x.second << " ";
    }
    cout << endl;
    mm.clear();
  }
  return 0;
}
