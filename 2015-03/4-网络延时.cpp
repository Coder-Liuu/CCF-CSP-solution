// 知识点: 树的直径 BFS DFS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
const int N = 10010;
vector<int> v[2*N];


int n,m;
int res;
int dist[2 * N];
bool st[2 * N];

int bfs(int start){
    memset(st,0,sizeof st);
    memset(dist,0,sizeof dist);
    queue<int> q;
    
    int end;
    q.push(start);
    st[start] = true;
    dist[start] = 0;
    
    while(q.size()){
        int now = q.front();
        q.pop();
        
        for(auto to: v[now]){
            if(!st[to]){
                q.push(to);
                st[to] = true;
                dist[to] = dist[now] + 1;
                end = to;
                
            }
        }
    }
    res = dist[end];
    return end;
}

int main(){
    cin >> n >> m;
    for(int i = 2; i <= n + m; i++){
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    
    int end1 = bfs(1);
    int end2 = bfs(end1);
    
    cout << res << endl;
    return 0;
}
