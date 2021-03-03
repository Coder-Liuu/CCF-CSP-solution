// 知识点: 强联通分量 tarjan算法
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 10010, M = 100010;

int n,m;
vector<int> v[N];
int dfn[N], low[N];
int stk[N], top, ts;
bool in_stk[N];
int ans;

void tarjan(int now){
    // 0. 准备遍历now这个点
    dfn[now] = low[now] = ++ ts;
    stk[++top] = now, in_stk[now] = true;
    for(int to:v[now]){
        // 1. 看看下一个点是否能更新当前点的时间戳
        if(!dfn[to]){
            tarjan(to);
            low[now] = min(low[now],low[to]);
        }
        // 2. 下一个点在栈中，看看能否更新当前点的时间戳
        else if(in_stk[to]) low[now] = min(low[now],low[to]);
    }
    // 3. 将当前节点进行出栈
    if(dfn[now] == low[now]){
        int y,cnt = 0;
        do{
            y = stk[top --];
            in_stk[y] = false;
            cnt++;
        }while(y != now);
        ans += cnt * (cnt - 1) / 2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    
    cout << ans << endl;
    return 0;
}



