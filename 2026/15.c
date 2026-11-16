#include <stdio.h>

int main(void)
{
   //基本となるデータ
   int steps;
   double exercise;
   double sleep;

   //ストレスの質問
   int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

   //気分の質問
   int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
   
   //食事の質問
   int f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
   //各要素
   double P1, P2, P3, P4, P5, P6;
   //トータルスコア(健康合計スコア)//
   double M;

   printf("これから健康度診断を始めます。昨日のデータを入力してください。\n");

   //~~~基本データ入力~~~

   printf("歩数を入力してください：");
   scanf("%d", &steps);

   printf("運動時間を入力してください（分）：");
   scanf("%lf", &exercise);

   printf("睡眠時間を入力してください（時間）：");
   scanf("%lf", &sleep);

   //＝質問について＝
   //　0 = 弱い・思わない
   //　10 = 強い・思う
   
   printf("\nこれから健康度測定のためストレス、気分、食事についての計30の問に答えてもらいます。");
   printf("\nこれらの各問は0～10の値で答えてください。（0：弱い・思わない、10：強い・思う）\n");
   printf("\n ~ ~ ~ ~ストレスについて~ ~ ~ ~ ");

   printf("\nQ1 学校生活で強いストレスを感じましたか？：");
   scanf("%d", &s1);

   printf("Q2 学校や課題に大きな負担を感じましたか？：");
   scanf("%d", &s2);

   printf("Q3 不安や心配事が頭から離れないことがありましたか？：");
   scanf("%d", &s3);

   printf("Q4 時間に余裕がないと感じましたか？：");
   scanf("%d", &s4);

   printf("Q5 人間関係で気を使うことがありましたか？：");
   scanf("%d", &s5);

   printf("Q6 イライラすることがありましたか？：");
   scanf("%d",&s6);

   printf("Q7 精神的に疲れていると感じることはありましたか？：");
   scanf("%d", &s7);

   printf("Q8 ゆっくりと休める時間が足りないと感じることはありましたか？：");
   scanf("%d", &s8);

   printf("Q9 普段より物事を行うときに面倒や疲れを感じましたか？：");
   scanf("%d", &s9);

   printf("Q10 胃が痛いや目が痛いなど、体調が悪いと感じることがありましたか？：");
   scanf("%d", &s10);

   //ストレススコア 
   double stress;

   stress =
      1.2 * s1 +
      1.2 * s2 +
      1.2 * s3 +
      1.0 * s4 +
      1.0 * s5 +
      1.0 * s6 +
      1.0 * s7 +
      0.8 * s8 +
      0.8 * s9 +
      0.8 * s10;
   P4 = 20 - stress / 2.5;

   printf("\n ~ ~ ~ ~気分について~ ~ ~ ~ ");

   printf("\nQ1 一日を通して気分が良かったですか？：");
   scanf("%d", &m1);

   printf("Q2 楽しいと感じる時間はありましたか？：");
   scanf("%d", &m2);

   printf("Q3 物事に取り組む意欲はありましたか？：");
   scanf("%d", &m3);

   printf("Q4 物事を前向きに考えられましたか？：");
   scanf("%d", &m4);

   printf("Q5 周りの人と楽しく過ごせましたか？：");
   scanf("%d", &m5);

   printf("Q6 リラックスできる時間がありましたか？：");
   scanf("%d", &m6);

   printf("Q7 好きなことや趣味を楽しめましたか？：");
   scanf("%d", &m7);

   printf("Q8 「今日はいい日だった」と感じましたか？：");
   scanf("%d", &m8);

   printf("Q9 何かに興味を持って取り組めましたか？：");
   scanf("%d", &m9);

   printf("Q10 今の自分に満足していますか？：");
   scanf("%d", &m10);

   //気分スコア
   double mood;

   mood =
      1.2 * m1 +
      1.2 * m2 +
      1.2 * m3 +
      1.0 * m4 +
      1.0 * m5 +
      1.0 * m6 +
      1.0 * m7 +
      0.8 * m8 +
      0.8 * m9 +
      0.8 * m10;

   P5 = -20 + 0.4 * mood;

   printf("\n ~ ~ ~ ~ 食事について~ ~ ~ ~ ");

   printf("\nQ1 朝・昼・夕の食事を規則的にとれましたか？：");
   scanf("%d", &f1);

   printf("Q2 野菜を意識して食べられましたか？：");
   scanf("%d", &f2);

   printf("Q3 バランスよく食事をすることができましたか？：");
   scanf("%d", &f3);

   printf("Q4 食事の時間が大きく乱れませんでしたか？：");
   scanf("%d", &f4);

   printf("Q5 食事を落ち着いて取ることができましたか？：");
   scanf("%d", &f5);

   printf("Q6 食事を抜くことはありませんでしたか？：");
   scanf("%d", &f6);

   printf("Q7 肉・魚・豆類などを食べられましたか？:");
   scanf("%d", &f7);

   printf("Q8 野菜や果物を食べることができましたか？：");
   scanf("%d", &f8);

   printf("Q9 十分に水分をとれましたか？：");
   scanf("%d", &f9);

   printf("Q10 食事全体に満足していましたか？：");
   scanf("%d", &f10);

   //食事スコア
   double food;

   food =
      1.2 * f1 +
      1.2 * f2 +
      1.2 * f3 +
      1.0 * f4 +
      1.0 * f5 +
      1.0 * f6 +
      1.0 * f7 +
      0.8 * f8 +
      0.8 * f9 +
      0.8 * f10;
   P6 = -20 + 0.4 * food;

   //歩数スコア
   P1 = 20 - (double)(steps - 8000) * (steps - 8000) / 2500000.0;

   //運動スコア
   P2 = 20 - (exercise - 150) * (exercise - 150) /1120.0;

   //睡眠スコア
   double sleepdiff;

   sleepdiff = sleep -8;

   P3 = 20 - sleepdiff * sleepdiff * sleepdiff * sleepdiff / 8.0;

   //トータルスコア
   M = P1 + P2 + P3 + P4 + P5 + P6;

   //健康度（S,A,B,C,Dで分ける）
   char rank;
   if (M >= 90)
   {
      rank = 'S';
   }
   else if (M >= 70)
   {
      rank = 'A';
   }
   else if (M >= 50)
   {
      rank = 'B';
   }
   else if (M >= 30)
   {
      rank = 'C';
   }
   else
   {
      rank = 'D';
   }

   //結果表示
   printf("\n= = = =健康スコア= = = =\n");
   printf("歩数スコア      : %.2f\n", P1);
   printf("運動スコア      : %.2f\n", P2);
   printf("睡眠スコア      : %.2f\n", P3);
   printf("ストレススコア  : %.2f\n", P4);
   printf("気分スコア      : %.2f\n", P5);
   printf("食事スコア      : %.2f\n", P6);
   printf("              [各最大20点]\n");
   printf("-------------------------\n");
   printf("総合健康スコア  : %.2f / 120\n", M);
   printf("あなたの健康度  : %c\n", rank);
   printf("= = = = = = = = = = = = =\n");
   printf("\n※この結果はあくまで目安です。医療的な診断を行うものではありません。");

}