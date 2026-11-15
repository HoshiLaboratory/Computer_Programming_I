#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_HISTORY 100

/* 計算履歴を保存するテーブル(配列) */
typedef struct {
    char label[30];   /* 何の計算か */
    double result;    /* 計算結果 */
} History;

History history[MAX_HISTORY];
int history_count = 0;

/* 履歴を1件追加する */
void add_history(const char *label, double result)
{
    if (history_count < MAX_HISTORY)
    {
        snprintf(history[history_count].label, sizeof(history[history_count].label), "%s", label);
        history[history_count].result = result;
        history_count++;
    }
    else
    {
        printf("履歴がいっぱいのため、これ以上保存できません\n");
    }
}

/* 履歴を全て表示する */
void show_history(void)
{
    int i;

    if (history_count == 0)
    {
        printf("履歴はまだありません\n");
        return;
    }

    printf("\n===== 計算履歴 =====\n");
    for (i = 0; i < history_count; i++)
    {
        printf("%2d: %-20s = %.2f\n", i + 1, history[i].label, history[i].result);
    }
}

/* 標準入力に残った余分な文字を読み捨てる(数字以外が入力されたときの対策) */
void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    int n;
    double a, b, result;

    while (1)
    {
        printf("\n");
        printf("===== 計算プログラム =====\n");
        printf("1. 四則演算\n");
        printf("2. 三角関数\n");
        printf("3. 平方根\n");
        printf("4. べき乗\n");
        printf("5. 角度の変換\n");
        printf("6. 計算履歴を見る\n");
        printf("0. 終了\n");
        printf("番号を入力してください：");

        if (scanf("%d", &n) != 1)
        {
            printf("数字を入力してください\n");
            clear_input();
            continue;
        }

        if (n == 0)
        {
            printf("終了します。\n");
            break;
        }

        if (n == 1)
        {
            char op;
            char label[30];

            printf("数字を2つ入力してください：");
            scanf("%lf %lf", &a, &b);

            printf("計算方法を入力してください（+ - * /）：");
            scanf(" %c", &op);

            if (op == '+')
            {
                result = a + b;
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "%.2f + %.2f", a, b);
                add_history(label, result);
            }
            else if (op == '-')
            {
                result = a - b;
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "%.2f - %.2f", a, b);
                add_history(label, result);
            }
            else if (op == '*')
            {
                result = a * b;
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "%.2f * %.2f", a, b);
                add_history(label, result);
            }
            else if (op == '/')
            {
                if (b == 0)
                {
                    printf("0では割れません\n");
                }
                else
                {
                    result = a / b;
                    printf("答えは %.2f です\n", result);
                    snprintf(label, sizeof(label), "%.2f / %.2f", a, b);
                    add_history(label, result);
                }
            }
            else
            {
                printf("入力が間違っています\n");
            }
        }

        else if (n == 2)
        {
            int x;
            double angle;
            char label[30];

            printf("角度を入力してください：");
            scanf("%lf", &angle);

            printf("1.sin  2.cos  3.tan\n");
            printf("番号を入力してください：");
            scanf("%d", &x);

            angle = angle * PI / 180;

            if (x == 1)
            {
                result = sin(angle);
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "sin");
                add_history(label, result);
            }
            else if (x == 2)
            {
                result = cos(angle);
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "cos");
                add_history(label, result);
            }
            else if (x == 3)
            {
                result = tan(angle);
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "tan");
                add_history(label, result);
            }
            else
            {
                printf("入力が間違っています\n");
            }
        }

        else if (n == 3)
        {
            char label[30];

            printf("数字を入力してください：");
            scanf("%lf", &a);

            if (a < 0)
            {
                printf("負の数は計算できません\n");
            }
            else
            {
                result = sqrt(a);
                printf("答えは %.2f です\n", result);
                snprintf(label, sizeof(label), "sqrt(%.2f)", a);
                add_history(label, result);
            }
        }

        else if (n == 4)
        {
            char label[30];

            printf("底の数を入力してください：");
            scanf("%lf", &a);

            printf("指数を入力してください：");
            scanf("%lf", &b);

            result = pow(a, b);
            printf("答えは %.2f です\n", result);
            snprintf(label, sizeof(label), "%.2f ^ %.2f", a, b);
            add_history(label, result);
        }

        else if (n == 5)
        {
            int x;
            char label[30];

            printf("角度を入力してください：");
            scanf("%lf", &a);

            printf("1. 度→ラジアン\n");
            printf("2. ラジアン→度\n");
            printf("番号を入力してください：");
            scanf("%d", &x);

            if (x == 1)
            {
                result = a * PI / 180;
                printf("答えは %.2f ラジアンです\n", result);
                snprintf(label, sizeof(label), "deg->rad");
                add_history(label, result);
            }
            else if (x == 2)
            {
                result = a * 180 / PI;
                printf("答えは %.2f 度です\n", result);
                snprintf(label, sizeof(label), "rad->deg");
                add_history(label, result);
            }
            else
            {
                printf("入力が間違っています\n");
            }
        }

        else if (n == 6)
        {
            show_history();
        }

        else
        {
            printf("正しい番号を入力してください\n");
        }
    }

    return 0;
}