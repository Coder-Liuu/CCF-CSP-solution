// 知识点: 数组 模拟
#include <iostream>
using namespace std;
int n;
const int N = 110;
int a[N][N];
int x1,x2,y1,y2;
int ans;
int main(){
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i < x2; i++) {
            for(int j = y1; j < y2; j++) {
                a[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i <= N - 1; i++) {
        for(int j = 0; j <= N - 1; j++) {
            if(a[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
