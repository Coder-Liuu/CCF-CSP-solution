#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 使用邻接表来存储
vector<int> a[10];
int n,m;
bool vis[10];

queue<int> q;
void bfs(int now){
  vis[now] = 1;
  q.push(now);
  while(!q.empty()){
    int now = q.front();q.pop();
    for(auto to: a[now]){
      if(!vis[to]){
        q.push(to);
        vis[to] = 1;
        cout << to << endl;
      }
    }
  }
}

int main(){
  cin >> n >> m;

  int u,v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  bfs(1);

  return 0;
}
