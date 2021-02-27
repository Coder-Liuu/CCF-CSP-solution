// 知识点: 数组 模拟
#include <iostream>
using namespace std;

const int N = 1010;
int g[N][N];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    
    
    for(int i = m - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            cout << g[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
