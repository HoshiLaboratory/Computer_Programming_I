#include <stdio.h>
int main(void){
     //変数の宣言
    float height;
    float weight;
    float bmi;
    float age;
    float Healthyweight;
    float gender;
    float basalmetabolicrate;
   
    //身長と体重の入力
    printf("Enter a height m => ");
    scanf("%f",&height);
    printf("%.2f m\n",height);
    printf("Enter a weight kg => ");
    scanf("%f",&weight);
    printf("%.1f kg\n",weight);
   
    //年齢の入力
    printf("Enter a age year => ");
    scanf("%f",&age);
    printf("%.0f\n",age);

    //適正体重の計算
    Healthyweight = (height*height*22);
    printf("your Healthy weight => %.1f kg\n",Healthyweight);
    printf("The difference from your ideal weight => %.1f kg\n",Healthyweight-weight);
   
    //BMI計算
    bmi = weight/(height*height);
    printf("your BMI => %.1f\n",bmi);
    //BMI判定とアドバイス
    if(bmi<18.5){
        printf("you are Underweight.Let's make sure you're getting enough nutrition.");
    }
    else if(bmi<25.0){
        printf("you are Normal range.Let’s keep it that way!");
    }
    else if(bmi<30.0){
        printf("you are Pre-obese.Try starting with small, healthy changes.");
    }
    else if(bmi<35.0){
        printf("you are Obese class 1.Small, healthy changes make a big difference.");
    }
    else if(bmi<40.0){
        printf("you are Obese class 2.Take it one step at a time. Consistency is key.");
    }
    else{
        printf("you are Obese class 3.Consulting a professional is a great first step.");
    }


    //性別の入力
    printf("Enter 1 for men, or 2 for women. =>\n");
    scanf("%f",&gender);

    //性別判定後に基礎代謝量計算
    if(gender==1||gender==2){
        basalmetabolicrate = ((0.1238+(0.0481*weight)+(0.0234*height*100)-(0.0138*age)-0.5473*gender))*1000/4.186;
        printf("Your estimated basal metabolic rate => %.0f kcal\n",basalmetabolicrate);
      }
     else{
        printf("Error");
    }


}