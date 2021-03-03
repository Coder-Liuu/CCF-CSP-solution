// 知识点: 数组 模拟
#include <iostream>
using namespace std;

const int N = 20;
int g[N][N];
int add[4][4];
int idx;


bool check(int k){
    if(k > 11) return true;
    int flag = 16;
    // 以第k层为例
    for(int j = 0; j < 4; j++){
        for(int i = idx; i < idx+4; i++){
            if(add[j][i-idx] == 1 && g[k+j][i] == 1) flag--;
        }
    }
    return flag == 16;
}
void plot(int k){
    for(int j = 0; j < 4; j++){
        for(int i = idx; i < idx+4; i++){
            if(!g[k+j][i]) g[k+j][i] = add[j][i-idx];
        }
    }
}

int main(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> add[i][j];
        }
    }
    cin >> idx;
    idx -= 1;
    
    for(int i = 0; i < 15; i++){
        // 下落,不能有重复
        if(!check(i) || i == 13){
            plot(i-1);
            break;
        }
    }
    
    
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j ++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

