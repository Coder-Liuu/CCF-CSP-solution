// 知识点：排列组合

#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1010, MOD = 1e9 + 7;
int n;
LL C[N][N];
LL res,t;
int main() {
    cin >> n;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }

    for(int k = 2; k <= n - 2; k++){
        t = C[n-1][k] * (k-1) % MOD;
        res = (res + t * (n-k-1) ) % MOD;
    }
    cout << res << endl;
    return 0;
}
