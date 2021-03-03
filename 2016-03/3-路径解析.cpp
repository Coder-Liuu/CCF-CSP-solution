#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int p,n;
string str;
vector<string> cmd;

// 手写分割字符串方法
vector<string> split(string s1){
  stringstream ss;
  ss.str(s1);
  string word;
  vector<string> res;
  while(getline(ss,word,'/')){
    if(word != "") res.push_back(word);
  }
  return res;
}

void query(){
  string s1;
  cin >> s1;
  vector<string> res = split(s1);
  vector<string> out;

  if(res.empty()){
    cout << "/" << endl;
    return;
  }

  if(res[0] == ".."){
    for(int i = 0; i < cmd.size() - 1; i++){
      out.push_back(cmd[i]);
    }
    for(int i = 1; i < res.size(); i++){
      out.push_back(res[i]);
    }
  }else if(res[0] == "."){
    for(int i = 0; i < cmd.size(); i++){
      out.push_back(cmd[i]);
    }
    for(int i = 1; i < res.size(); i++){
      out.push_back(res[i]);
    }
  }else{
    for(int i = 0; i < res.size(); i++){
      out.push_back(res[i]);
    }
  }

  for(auto it=out.begin(); it!=out.end(); it++){
    if(*it == ".") out.erase(it--);
  }

  for(int i = 0; i < out.size(); i++){
    if(out[i] == ".." && i == 0){
      for(int j = 0; j < out.size() - 1; j++){
          out[j] = out[j+1];
      }
      out.pop_back();
      i-=1;
    }

    if(out[i] == ".." && i != 0){
      int flag = 1;
      for(int j = i; j < out.size(); j++){
        if(j-2 >= 0) {
          out[j-2] = out[j];
          flag = 1;
        }
      }
      if(flag){
        out.pop_back();
        out.pop_back();
      }
      i-=2;
    }
  }


  for(int i = 0; i < out.size(); i++){
    cout << '/'<< out[i];
  }
  cout << endl;
}

int main(){
  cin >> n >> str;
  cmd = split(str);
  for(int i = 0; i < n; i++){
    query();
  }
  return 0;
}
