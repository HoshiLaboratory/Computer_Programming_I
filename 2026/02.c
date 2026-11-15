// gcc -o kadai kadai.c
// 実行モジュールを実行する
//./kadai

#include<stdio.h>

int main(){
    int year,month,day;
    long JDN;
    long mayanDays;

    printf("西暦　年　月　日　を入力してください");
    scanf("%d %d %d",&year,&month,&day);

    int a = (14 - month)/12;
    int y = year + 4800 - a;
    int m = month + 12*a - 3;

    JDN = day + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    mayanDays = JDN - 584283;

    if (mayanDays < 0){
        printf("マヤ暦開始以前の日付です\n");
        return 0;
    }

    int bakutun = mayanDays/144000;
    mayanDays %=144000;
    
    int katun = mayanDays/7200;
    mayanDays %=7200;
    
    int tun = mayanDays/360;
    mayanDays %=360;
    
    int uinal = mayanDays/20;
    int kin = mayanDays % 20;

    printf("\nマヤ暦\n");
    printf("%d.%d.%d.%d.%d\n",bakutun,katun,tun,uinal,kin);
    return 0;
}