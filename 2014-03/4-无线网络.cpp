// 知识点: 较难BFS
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

int n,m,k,r;
const int N = 220;
vector<int> g[N];
PII p[N];

bool check(PII a,PII b){
  LL dx = a.first - b.first;
  LL dy = a.second - b.second;
  return dx * dx + dy * dy <= (LL)r * r;
}

int bfs(){
  queue<PII> q;
  int dist[N][N];
  memset(dist,0x3f,sizeof(dist));
  dist[1][0] = 0;
  // 到i点，经过0个特殊点
  q.push({1,0});

  while(q.size()){
    auto t = q.front();
    q.pop();

    // 开始遍历出边
    for(int to:g[t.first]){
      // 找到相邻的那个点 的下标是to
      int x = to;
      int y = t.second;
      if(x > n) y++;
      if(y <= k){
        if(dist[x][y] > dist[t.first][t.second] + 1){
          dist[x][y] = dist[t.first][t.second] + 1;
          q.push({x,y});
        }
      }
    }
  }

  int res = 1e8;
  for(int i = 0; i <= k; i++){
    res = min(res,dist[2][i]);
  }
  return res - 1;
}

int main(){
  cin >> n >> m >> k >> r;
  for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
  for(int i = n + 1; i <= n + m; i++) cin >> p[i].first >> p[i].second;

  for(int i = 1; i <= n + m; i++){
    for(int j = i + 1; j <= n + m; j++){
      if(check(p[i],p[j])){
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  cout << bfs();
  return 0;
}

