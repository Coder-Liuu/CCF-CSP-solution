// 知识点: 模拟 差分
#include <iostream>
using namespace std;

int n;
const int N = 1010;
int a[N],b[N];
int res;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        a[i] = b[i] - b[i-1];
    }

    a[1] = 0;
    for(int i = 1; i < n; i++){
        if(a[i] * a[i+1] < 0){
            res++;
        }
    }
    cout << res << endl;
}
