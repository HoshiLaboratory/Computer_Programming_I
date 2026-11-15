#include <stdio.h> // printfとscanf
#include <stdlib.h> // srandとrand
#include <time.h> // time

int main(void) {

    int a;
    int b;
    int r;

    // 乱数の初期化
    srand((unsigned int)time(NULL));

    do {
        // コンピューターが出す手を決定する
        b = rand() % 3;

        // プレイヤーが出す手の入力を受け付ける
        while (1) {
            printf("何を出しますか？（ 0:グー / 1:チョキ / 2:パー ）:");
            scanf("%d", &a);

            if (a >= 3 || a < 0) {
                printf("出した手がおかしいです もう一度やり直してください./zyannken...\n\n");
            } else {
                break;
            }
        }
        printf("\n");
0
        // プレイヤーとコンピューターが出した手を表示する
        printf("あなたが出した手:");
        if (a == 0) {
            printf("グー\n");
        } else if (a == 1) {
            printf("チョキ\n");
        } else if (a == 2) {
            printf("パー\n");
        }

        printf("相手が出した手　:");
        if (b == 0) {
            printf("グー\n");
        } else if (b == 1) {
            printf("チョキ\n");
        } else if (b == 2) {
            printf("パー\n");
        }
        printf("\n");

        // じゃんけんの結果を判断する
        if (a == b) {
            r = 0;
        } else if (
            a == 0 && b == 1 ||
            a == 1 && b == 2 ||
            a == 2 && b == 0
        ) {
            r = 1;
        } else {
            r = 2;
        }

        // じゃんけんの結果を表示する
        printf("結果は・・・");
        if (r == 0) {
            printf("引き分けです!!!\n");
        } else if (r == 1) {
            printf("あなたの勝ちです!!!\n");
        } else {
            printf("あなたの負けです...\n");
        }
        printf("\n");

    } while (r == 0);

}