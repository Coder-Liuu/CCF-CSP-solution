// 知识点: 多源BFS
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

int dr[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const int N = 1010;
int dist[N][N];  // 距离矩阵
bool g[N][N];    // 障碍标记
int n,m,k,d;
queue< PII > q;

struct Target{
    int x,y,c;
}tg[N * N];

void bfs(){
    while(q.size()){
        PII top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        
        for(int i = 0; i < 4; i++){
            int tx = x + dr[i][0];
            int ty = y + dr[i][1];
            if(g[tx][ty] || tx < 1 || ty < 1 || tx > n || ty > n) 
                continue;
            if(dist[tx][ty] > dist[x][y] + 1){
                q.push({tx,ty});
                dist[tx][ty] = dist[x][y] + 1;                
            }
        }
    }
}


// 方格图的大小、栋栋的分店数量
// 客户的数量，以及不能经过的点的数量。
int main(){
    ios::sync_with_stdio(false);
    memset(dist,0x3f,sizeof(dist));
    
    cin >> n >> m >> k >> d;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        dist[x][y] = 0;
        q.push({x,y});
    }
    for(int i = 0; i < k; i++){
        cin >> tg[i].x >> tg[i].y >> tg[i].c;
    }
    for(int i = 0; i < d; i++){
        int x,y;
        cin >> x >> y;
        g[x][y] = true;
    }
    
    bfs();
    LL res = 0;
    
    for(int i = 0; i < k; i++){
        res += dist[tg[i].x][tg[i].y] * tg[i].c;
    }
    
    cout << res << endl;
    return 0;
}

