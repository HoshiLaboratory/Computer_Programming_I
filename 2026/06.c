# include <stdio.h>
# include <time.h>  //時間計算のため
# include <math.h>
#include <string.h>

int main()
{

    //マヤ暦

    printf("\n\n    マヤ暦に変換したい年月日を半角数字で順番に入力\n年>>");
    int year;
    scanf("%d",&year);
   
    printf("月>>");
    int month;
    scanf("%d",&month);

    printf("日>>");
    int day;
    scanf("%d",&day);

    struct tm ref;

    ref.tm_year = year - 1900;
    ref.tm_mon = month - 1;
    ref.tm_mday = day; 
    ref.tm_hour = 0;
    ref.tm_min = 0;
    ref.tm_sec = 0;
    ref.tm_isdst = 0;

    time_t refTime = mktime(&ref);
    const time_t MAYA_EPOCH = -160000032000LL;
    double diff = difftime(refTime,MAYA_EPOCH);
    double totalday = (diff/(60*60*24));

    char maya_keisu[][15] = 
    {
        "イミシュ",
        "イク",
        "アクバル",
        "カン",
        "チクチャン",
        "キミ",
        "マニク",
        "ラマト",
        "ムルク",
        "オク",
        "チュエン",
        "エブ",
        "ベン",
        "イシュ",
        "メン",
        "キブ",
        "カバン",
        "エツナブ",
        "カワク",
        "アハウ"
    };
 
    long day_int = (long)totalday;
    int keisu = (day_int % 20 + 12) % 20; //+12は紋章の補正
    int maya_day = (day_int % 13 + +11) % 13; //+11はKINの補正
    if (maya_day == 0) {
        maya_day = 13;
    }
    printf("%dKIN\n",maya_day);
    printf("%s\n",maya_keisu[(int)keisu]);


    //太陰暦

    int lunar_year, lunar_month, lunar_day;

    printf("\n太陰暦に変換したい年月日を半角数字で順番に入力\n年>>");
    scanf("%d", &lunar_year);

    printf("月>>");
    scanf("%d", &lunar_month);

    printf("日>>");
    scanf("%d", &lunar_day);

    int leap;

    if (lunar_year%400== 0)
    {
        leap=1;
    }

    else if(lunar_year % 100 ==0)
    {
        leap=0;
    }

    else if(lunar_year % 4==0)
    {
        leap=1;
    }

    else
    {
        leap=0;
    }

    int a = (lunar_year-1)/4-(lunar_year-1)/100+(lunar_year-1)/400;

    int lunar_month_lunar_days [12];

    lunar_month_lunar_days[0]=31;

    lunar_month_lunar_days[1]=28;

    lunar_month_lunar_days[2]=31;

    lunar_month_lunar_days[3]=30;

    lunar_month_lunar_days[4]=31;

    lunar_month_lunar_days[5]=30;

    lunar_month_lunar_days[6]=31;

    lunar_month_lunar_days[7]=31;

    lunar_month_lunar_days[8]=30;

    lunar_month_lunar_days[9]=31;

    lunar_month_lunar_days[10]=30;

    lunar_month_lunar_days[11]=31;

    if(leap == 1) 
    {
        lunar_month_lunar_days[1] = 29;
    }

    int i;
    int total;

    total = 0;

    for (i=0; i<(lunar_month-1);i++) 
    {
        total += lunar_month_lunar_days[i];
    }

    int b = (lunar_year - 1) * 365 + a + total + (lunar_day - 1);


    int three_lunar_years = b/1092;

    int c = three_lunar_years * 3;

    int rest = b % 1092;

    int rest_lunar_days;

    if (rest<354)
    {
        rest_lunar_days=rest;
    }

    else if (rest<708)
    {
    c=c+1;
    rest_lunar_days= rest - 354;
    }

    else
    {
    c=c+2;
    rest_lunar_days= rest - 708;
    }


    int lunar_month_n [13];

    lunar_month_n[0]=30;

    lunar_month_n[1]=29;

    lunar_month_n[2]=30;

    lunar_month_n[3]=29;

    lunar_month_n[4]=30;

    lunar_month_n[5]=29;

    lunar_month_n[6]=30;

    lunar_month_n[7]=29;

    lunar_month_n[8]=30;

    lunar_month_n[9]=29;

    lunar_month_n[10]=30;

    lunar_month_n[11]=29;

    lunar_month_n[12]=30;

    int lunar_month_result=1;

    int j;

    for (j=0;j<13;j++)
    {
        if(rest_lunar_days>=lunar_month_n[j])
        {
            rest_lunar_days -=lunar_month_n[j];
            lunar_month_result ++;
        }
    }

    printf("year:%d month:%d days:%d\n",c,lunar_month_result,rest_lunar_days+1);
}