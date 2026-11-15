#include "stdio.h"
#include "string.h"
typedef struct stationtime
{
    int Mon;
    int day;
    int hours;
    int minutes;
} StationTime;
typedef struct stationname
{
    char Tokyo[20];
    char SinOsaka[20];
    char Nagoya[20];
} StationName;
// 到着時刻の関数
int arivval_time(StationTime *stime)
{
    // 時間の繰り上げ
    if (stime->minutes >= 60)
    {
        stime->hours += stime->minutes / 60;
        stime->minutes =
            stime->minutes % 60;
    }
    // 日にちの繰り上げ
    if (stime->hours >= 24)
    {
        stime->day += stime->hours / 24;
        stime->hours = stime->hours % 24;
    }
    return 1;
}
int main()
{
    StationName sname = {
        "東京", "大阪", "名古屋"};
    StationTime stime = {0};
    while (1)
    {
        printf("月を入力してください(1~12)\n");
        scanf("%d", &stime.Mon);
        if (stime.Mon > 12 || stime.Mon < 1)
        {
            printf("入力が間違っています。\n");
            continue;
        }
        printf("日にちを入力してください(1~31)\n");
        scanf("%d", &stime.day);
        if (stime.day > 31 || stime.Mon < 1)
        {
            printf("入力が間違っています。\n");
            continue;
        }
        printf("出発時刻を入力してください(~時~分)\n");
        scanf("%d時%d分", &stime.hours, &stime.minutes);
        if (stime.hours > 24 || stime.hours < 0 || stime.minutes > 60 || stime.minutes < 0)
        {
            printf("入力が間違っています。\n");
            continue;
        }
        printf("%d月%d日%d時%d分に", stime.Mon, stime.day, stime.hours, stime.minutes);
        break;
    }

    char startstation[20];
    char finishstation[20];

    while (1)
    {
        printf("出発する駅を入力して下さい(東京,名古屋,新大阪)\n");
        scanf("%s", startstation);
        printf("到着する駅を入力してください(東京,名古屋,新大阪)\n");
        scanf("%s", finishstation);

        // 東京=>名古屋
        // 名古屋=>東京
        if (strcmp(sname.Tokyo, startstation) == 0 && strcmp(sname.Nagoya, finishstation) == 0 || strcmp(sname.Nagoya, startstation) == 0 && strcmp(sname.Tokyo, finishstation))
        {
            stime.minutes += 95;
            arivval_time(&stime);
            printf("%s =>%s %d月%d日%d時%d分に到着", startstation, finishstation, stime.Mon, stime.day, stime.hours, stime.minutes);
            break;
        }
        // 東京=>新大阪
        // 新大阪=>東京
        else if (strcmp(sname.SinOsaka, startstation) == 0 && strcmp(sname.Tokyo, finishstation) == 0 || strcmp(sname.Tokyo, startstation) == 0 && strcmp(sname.SinOsaka, finishstation))
        {
            stime.minutes += 145;
            arivval_time(&stime);
            printf("%s =>%s %d月%d日%d時%d分に到着", startstation, finishstation, stime.Mon, stime.day, stime.hours, stime.minutes);
            break;
        }

        // 名古屋=>新大阪
        // 新大阪=>名古屋
        else if (strcmp(sname.SinOsaka, startstation) == 0 && strcmp(sname.Nagoya, finishstation) == 0 || strcmp(sname.Nagoya, startstation) == 0 && strcmp(sname.SinOsaka, finishstation))
        {
            stime.minutes += 50;
            arivval_time(&stime);
            printf("%s =>%s %d月%d日%d時%d分に到着", startstation, finishstation, stime.Mon, stime.day, stime.hours, stime.minutes);
            break;
        }
        else
        {
            printf("入力された駅が見つかりませんでした。\n");
            printf("もう一度入力をお願いします。\n");
        }
    }
    return 0;
}
