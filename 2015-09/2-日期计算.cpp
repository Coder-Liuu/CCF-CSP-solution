// 知识点: 日期计算
#include <iostream>
using namespace std;

int y,d;

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int leap_year(int year) {
    return ((year%4 == 0 && year%100 != 0) || year%400 == 0) ? 1 : 0;
}
int get_days(int year,int month){
    if(month == 2) return 28 + leap_year(year);
    return months[month];
}

int main(){
    cin >> y >> d;
    int day = 1;
    int month = 1;
    int count = 1;
    while(count < d){
        count++;
        day++;
        if( day > get_days(y,month) ){
            day = 1;
            month++;
        }
    }
    cout << month << endl << day << endl;
    return 0;
}
