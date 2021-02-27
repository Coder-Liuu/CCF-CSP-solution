// 知识点: 结构体排序
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 1010;
int n;

struct num{
    int x,y;
}nums[N];


bool cmp(num a,num b){
    if(a.y > b.y) return true;
    else if(a.y < b.y) return false;
    if(a.x < b.x) return true;
    return false;
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        nums[b].x = b;
        nums[b].y += 1;
    }
    sort(nums,nums+N,cmp);
 
    for(auto t : nums){
        if(t.y == 0) break;
        cout << t.x << " " << t.y << endl;
    }
    return 0;
}
