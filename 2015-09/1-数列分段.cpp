// 知识点: 遍历
#include <iostream>
using namespace std;

const int N = 1010;
int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];
    
    int pred = -1;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(q[i] == pred) continue;
        pred = q[i];
        res++;
    }
    cout << res << endl;
    return 0;
}
