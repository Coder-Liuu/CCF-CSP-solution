// 知识点: 模拟
#include <iostream>
using namespace std;

int n,res;
int main(){
    cin >> n;
    while(n){
        res += n % 10;
        n /= 10;
    }
    cout << res << endl;
    return 0;
}
