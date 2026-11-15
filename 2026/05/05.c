#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool get_ariable(char *station, int time, int *buff);

int main(void)
{
    int anser = 0;
    while (anser == 0)
    {

        char buffer[6] = "test";
        int times = 0;
        int get_times = 0;
        printf("あなたが使いたい駅はどれですか?(JR or Keisei)>>"); // ここで駅名を聞く文を出力
        scanf("%s", buffer);                                       // buffer内にuser側の回答を入れる
        printf("あなたが入力したのは%s\n", buffer);                // 何を入れたか出力

        printf("今何時?>>");                           // ここで時間を入力
        scanf("%d", &get_times);                       // get_times内にuser側の回答を入れる
        printf("あなたが入力したのは%d\n", get_times); // 何を入れたか出力

        if (get_ariable(buffer, get_times, &times))
        {
            printf("%d\n", times);
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
/// @brief 直近の出発時刻があるかを返す関数
/// @param[in] station_ 時刻表のCSVファイル名
/// @param[in] time_ 基準時間,この時間から直近の時刻を探す
/// @param[out] buff_ 直近の時刻を入れる変数
/// @return 直近の時刻があるかどうか,ないとfalseがあるとtrueが返る
bool get_ariable(char *station_, int time_, int *buff_)
{
    char file_name[sizeof(station_) + 6 + 4] = "";
    sprintf(file_name, "%s%s%s", "./csv/", station_, ".csv"); // ファイルパスの作成
    FILE *fptr = fopen(file_name, "r");                       // 読みモードでファイルを開く
    if (fptr == NULL)
    {
        return 0;
    }
    char buff[20] = "";
    bool flag = false;
    for (int i = 0; i < 1024; i++)
    {
        fgets(buff, 20, fptr); // CSVから1行分入手
        char *ptr_flag = 0;
        char get_buff[6] = "";
        int get_time = 0;
        strncpy(get_buff, strtok(buff, ","), 6);    // CSVの","までの値を入手
        get_time = strtol(get_buff, &ptr_flag, 10); // 文字列から整数に変換
        if ((get_time - time_) >= 0)                // 直近の値かどうかを調べる
        {
            *buff_ = get_time;
            flag = true;
            break;
        }
    }
    fclose(fptr); // ファイルを閉じる
    return (true) ? 1 : 0;
}
