#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum wday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Sataday};

main(int argc, char *argv[])
{
    time_t t = time(NULL); // 現時刻の情報を取得
    struct tm local = *localtime(&t); // 現地(に変換 tm 構造体に格納
    
    if (argc == 2) {
        int num = atoi(argv[1]);
        local.tm_wday = (local.tm_wday + num) % 7;
    }

    switch (local.tm_wday){
        case Sunday:
            printf("Sunday\n");
            printf("Today is a holiday!\n");
            break;
        case Monday:
            printf("Monday\n");
            break;
        case Tuesday:
            printf("Tuesday\n");
            printf("We take the programming 3 class today!\n");
            break;
        case Wednesday:
            printf("Wednesday\n");
            break;
        case Thursday:
            printf("Thursday\n");
            break;
        case Friday:
            printf("Friday\n");
            break;
        case Sataday:
            printf("Sataday\n");
            printf("Today is a holiday!\n");
            break;
    }    

    return 0;
}