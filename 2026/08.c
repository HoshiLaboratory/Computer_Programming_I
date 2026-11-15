#include <stdio.h>

int main(void) {
    double height, weight;
    int exercise, age, gender;
    double height_m, bmi, standard_weight;

    printf("=== 健康管理プログラム ===\n\n");

    printf("身長(cm)を入力してください: ");
    scanf("%lf", &height);

    printf("体重(kg)を入力してください: ");
    scanf("%lf", &weight);

    printf("年齢を入力してください: ");
    scanf("%d", &age);

    printf("性別を入力してください (1: 男性, 2: 女性): ");
    scanf("%d", &gender);

    printf("週の運動頻度を入力してください (1: ほぼなし, 2: 週1〜2日, 3: 週3日以上): ");
    scanf("%d", &exercise);

    height_m = height / 100.0;
    bmi = weight / (height_m * height_m);
    standard_weight = height_m * height_m * 22.0;

    printf("\n----------------------------------------\n");
    printf("【計算結果】\n");
    printf("あなたのBMI: %.2f\n", bmi);
    printf("あなたの標準体重: %.2f kg\n", standard_weight);

    printf("判定: ");
    if (bmi < 18.5) {
        printf("低体重（やせ）\n");
    } else if (bmi < 25.0) {
        printf("標準\n");
    } else {
        printf("肥満\n");
    }

    printf("\n【健康アドバイス】\n");
    if (bmi < 18.5) {
        printf("・体脂肪が少なめです。バランスの良い食事でしっかり栄養を摂りましょう。\n");
    } else if (bmi < 25.0) {
        printf("・理想的な体型です！現在の生活習慣を維持しましょう。\n");
    } else {
        printf("・適正体重を超えています。食事の量や内容を見直してみましょう。\n");
    }

    if (exercise == 1) {
        printf("・運動不足気味です。まずはエスカレーターではなく階段を使うなど、日常の活動量を増やしてみましょう。\n");
    } else if (exercise == 2) {
        printf("・適度に運動できています！もう少し頻度を増やすとさらに効果的です。\n");
    } else {
        printf("・素晴らしい運動習慣です！怪我に気をつけながら継続してください。\n");
    }

    printf("----------------------------------------\n");

    return 0;
}
