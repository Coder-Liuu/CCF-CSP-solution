// 知识点: 日期问题 模拟
#include <iostream>
#include <cstring>
using namespace std;

int a,b,c,y1,y2;
int day_num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int wek[8] = {0,0,0,0,0,0,0,0}; 
    
int main(){
    cin >> a >> b >> c >> y1 >> y2;
    int day = 1;
    int month = 1;
    int year = 1850;
    
    int week = 1;

    int week_day = 2;
    int flag = 1;
    
    while(year <= y2){

        if(week_day > 7){
            week_day = 1;
        }
        wek[week_day]++;
        
        if(year >= y1 && month == a && wek[week_day] == b && week_day == c){
            cout << year << "/";
            if(month < 10) cout << "0" << month;
            else cout << month;
            cout << "/";
            if(day < 10) cout << "0" << day;
            else cout << day;
            cout << endl;
            flag = 0;
        }       
        
        
        day++;
        week_day++;
        if(day > day_num[month]){
            memset(wek,0,sizeof wek);
            
            month++;
            day = 1;
            if(month > 12){
                if(flag && year >= y1){
                    cout << "none" << endl;
                }else{
                    flag = 1;
                }
                year++;
                month = 1;
                if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    day_num[2] = 29;
                else
                    day_num[2] = 28;
            }
        }
    }
    
    return 0;
}
