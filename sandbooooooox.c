#include<stdio.h>


int uruu(int year) {
// うるう年なら１、そうでなければ０を返す
// たとえば uruu(2000)=1, uruu(2001)=0となる。
    int tmp = 0;
    if (year % 400 == 0) tmp = 1;
    else if (year % 4 == 0 && year % 100 != 0)tmp = 1;
    return tmp;
}

int num_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calender(int year, int month, int date) {
    int totalDays = 0;

    for (int i = 0; i < year - 2000; ++i) {
        totalDays += 365 + uruu(2000 + i);
    }

    for (int i = 0; i < month - 1; ++i) {
        if (uruu(year) && i == 1) {
            totalDays += num_of_month[i] + 1;
        } else totalDays += num_of_month[i];
    }
    totalDays += date;
    return totalDays;


}
//2000,1,3は月
int WHEN(int totalDays){
    switch ((totalDays -2) % 7) {
        case 0:
            printf("日曜日\n");
            break;
        case 1:
            printf("月曜日\n");
            break;
        case 2:
            printf("火曜日\n");
            break;
        case 3:
            printf("水曜日\n");
            break;
        case 4:
            printf("木曜日\n");
            break;
        case 5:
            printf("金曜日\n");
            break;
        case 6:
            printf("土曜日\n");
            break;
    }
}

int main() {
    int totalDays = calender(2022, 10, 6);
    printf("日｜月｜火｜水｜木｜金｜土");
    (calender(2022,10,1) - 1) % 7;
    WHEN(calender(2000,1,1));


   /* switch ((totalDays - 1) % 7) {
        case 0:
            printf("土曜日\n");
            break;
        case 1:
            printf("日曜日\n");
            break;
        case 2:
            printf("月曜日\n");
            break;
        case 3:
            printf("火曜日\n");
            break;
        case 4:
            printf("水曜日\n");
            break;
        case 5:
            printf("木曜日\n");
            break;
        case 6:
            printf("金曜日\n");
            break;
    }*/
    //printf("%d\n", );
    //  printf("%d\n",uruu(2001));
    return 0;
}
