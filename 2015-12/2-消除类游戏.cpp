// 知识点: 数组 模拟
#include <iostream>
using namespace std;

const int N = 50;
int n,m;
int g[N][N];
int book[N][N];

void check_x(int i,int j){
    int t = book[i][j];
    int count = 0;
    for(int k = j; k < m; k++){
        if(g[i][k] == 0 && book[i][k] == t) count++;
        else if(g[i][k] == t) count++;
        else break;
    }
    if(count >= 3){
        for(int k = j; k < j + count ; k++){
            if(g[i][k] == t) g[i][k] = 0;
        }        
    }
}

void check_y(int i,int j){
    int t = book[i][j];
    int count = 0;
    for(int k = i; k < n; k++){
        if(g[k][j] == 0 && book[k][j] == t) count++;
        else if(g[k][j] == t) count++;
        else break;
    }
    if(count >= 3){
        for(int k = i; k < i + count; k++){
            if(g[k][j] == t) g[k][j] = 0;
        }        
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            book[i][j] = g[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check_x(i,j);
            check_y(i,j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
