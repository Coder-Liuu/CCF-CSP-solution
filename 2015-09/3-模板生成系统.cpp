// 知识点: 字符串处理
#include <iostream>
#include <utility>
#define x first
#define y second
using namespace std;

typedef pair<string,string> PSS;


const int N = 110;
int n,m;
string doc[N];
PSS var[N];

void get_var(int k){
    int len = var[k].y.length();
    for(int i = 1; i < len - 1; i++)
        cout << var[k].y[i];
}

void solve(){
    for(int i = 0; i < n; i++){
        string top = doc[i];
        int len = top.length();
        int j = 0;       
        
        while(j < len){
            while( !(top[j] == '{' && top[j+1] == '{') && j < len){
                cout << top[j++];
            }
            if(j == len) break;

            int t;
            int k = 0;
            for(k = 0; k < m; k++){
                int s2i = 0;
                t = j + 3;
                string s2 = var[k].x;
                while(top[t++] == s2[s2i++]);
                if(s2i == s2.length() + 1) {
                    get_var(k);
                    break;
                }
            }
            j = t + 2;
            if(k == m){
                while(j < len && top[j++] != '}');
                j += 1;
            }
        }
        
        cout << endl;
    }
}

int main(){
    cin >> n >> m;
    
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin,doc[i]);
    }
    for(int i = 0; i < m; i++){
        string a,b;
        cin >> a;
        getchar();
        getline(cin,b);
        var[i].x = a;
        var[i].y = b;
        int len = b.length();
    }
    
    solve();
    return 0;
}
