// 知识点: 搜索 DFS
#include <iostream>
using namespace std;

const int N = 110;
int n,m,q;
int g[N][N];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char d[N];
int idx = 1;

void line(int x1,int y1,int x2,int y2){
    int flag;
    if(x1 == x2) flag = -1;
    if(y1 == y2) flag = -2;
    
    for(int i = min(x1,x2);i <= max(x1,x2); i++){
        for(int j = min(y1,y2);j <= max(y1,y2); j++){
            if(g[i][j] >=0) g[i][j] = flag;
            if(g[i][j] == -1 && flag == -2) g[i][j] = -3;
            if(g[i][j] == -2 && flag == -1) g[i][j] = -3;
        }
    }
}

void dfs(int x1,int y1){
    for(int i = 0; i < 4; i++){
        int tx = x1 + dir[i][0];
        int ty = y1 + dir[i][1];
        if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
        if(g[tx][ty] < 0) continue;
        if(g[tx][ty] == idx) continue;
        g[tx][ty] = idx;
        dfs(tx,ty);
    }
}

void check(int x,int y){
    if(g[x][y] == 0) cout << '.';
    else if(g[x][y] == -2) cout << '-';
    else if(g[x][y] == -1) cout << '|';
    else if(g[x][y] == -3) cout << '+';
    else cout << d[g[x][y]];
}

int main(){
    int mode;
    int x1,y1,x2,y2;

    
    cin >> n >> m >> q;
    // n行m列
    
    while(q--){
        cin >> mode;
        if(mode == 1){
            char dd;
            cin >> x1 >> y1 >> dd;
            d[idx] = dd;
            g[x1][y1] = idx;
            dfs(x1,y1);
            
            idx++;
        }else{
            cin >> x1 >> y1 >> x2 >> y2;
            line(x1,y1,x2,y2);
        }
    }
    
    
    for(int j = m - 1; j >= 0; j--){
        for(int i = 0; i < n; i++){
            check(i,j);
        }
        cout << endl;
    }
    return 0;
}
