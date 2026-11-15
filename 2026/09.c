#include <stdio.h>

int main(void) {
    int year, month, day;
    int a, y, m, jdn, mayan_days;
    int baktun, katun, tun, uinal, kin;

    printf("西暦の年を入力してください: ");
    scanf("%d", &year);
    printf("月を入力してください: ");
    scanf("%d", &month);
    printf("日を入力してください: ");
    scanf("%d", &day);

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("\nエラー: 存在しない日付、または対応していない値が入力されました。\n");
        return 1;
    }

    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    mayan_days = jdn - 584283;

    baktun = mayan_days / 144000;
    mayan_days = mayan_days % 144000;

    katun = mayan_days / 7200;
    mayan_days = mayan_days % 7200;

    tun = mayan_days / 360;
    mayan_days = mayan_days % 360;

    uinal = mayan_days / 20;
    kin = mayan_days % 20;

    printf("\n--- 変換結果 ---\n");
    printf("西暦: %d年%d月%d日\n", year, month, day);
    printf("マヤ暦: %d.%d.%d.%d.%d\n", baktun, katun, tun, uinal, kin);

    return 0;
}