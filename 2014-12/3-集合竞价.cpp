// 知识点: 大模拟
#include <iostream>
#include <utility>
using namespace std;
typedef pair<float,int> PII;
typedef long long LL;

const int N = 5050;
string mode;
float p0;
int s;
PII a[N];
int st[N];


int main(){
  ios::sync_with_stdio(0);
  int head = 1;
  // 输入
  while(cin >> mode){
    if(mode == "cancel"){
      cin >> s;
      st[s] = -1;
      a[s].second = 0;
      head++;
      continue;
    }
    cin >> p0 >> s;
    if(mode == "buy") st[head] = 1;
    a[head].first = p0; a[head].second = s;
    head++;
  }
  // 两重循环
  LL res = 0;
  float res_p0 = 0;
  for(int i = 0; i < head; i++){
    if(st[i] == -1) continue;

    float cnt = a[i].first;
    LL res1 = 0, res2 = 0;

    for(int j = 0; j < head; j++){
      if(st[j] == 1 && a[j].first >= cnt) res1 += a[j].second;
      if(st[j] == 0 && a[j].first <= cnt) res2 += a[j].second;
    }

    LL ans = min(res1,res2);
    if(ans > res){
      res = ans;
      res_p0 = cnt;
    }
    if(ans == res) res_p0 = max(res_p0,cnt);
  }

  ios::sync_with_stdio(1);
  printf("%.2f %lld",res_p0,res);
  return 0;
}
