// 知识点: 最小生成树算法 Prim算法 Kruskal算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int g[N][N],dist[N],st[N];
int n,m;

int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        if(i) res += dist[t];
        st[t] = true;
        
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    
    cout << prim();
    return 0;
}
