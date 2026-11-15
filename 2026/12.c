#include <stdio.h>
#include <math.h>

int main(void)
{
    double solute;
    double solvent;
    double solution;
    double concentration;
    int significant;

    printf("溶質の質量(g)を入力してください：");
    scanf("%lf", &solute);

    printf("溶媒の質量(g)を入力してください：");
    scanf("%lf", &solvent);

    printf("有効桁数を入力してください：");
    scanf("%d", &significant);

    solution = solute + solvent;
    concentration = solute / solution * 100;

    printf("溶液の質量：%.2f g\n", solution);

　　char hoshi[30]; 
　　int int_digits = sprintf(hoshi, "%d", (int)concentration); 
　　int decimals = significant -　int_digits; 
　　if (decimals < 0) {
　　　　decimals = 0;
    }

    printf("質量パーセント濃度：%.*g %%\n", significant, concentration);

    return 0;
}
