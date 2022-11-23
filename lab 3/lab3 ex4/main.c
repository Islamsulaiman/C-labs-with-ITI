#include <stdio.h>
#include <stdlib.h>

void bigger();

void main()
{
    int num1=0, num2=0, num3=0;
    printf("Please enter three values to choose the bigger from \n");
    scanf("%d %d %d",&num1, &num2, &num3);

    bigger(num1, num2, num3);

}

void bigger(int num1, int num2, int num3){
    int try = 0;

    if(num1 > num2 && num1 > num3){
        printf("\n %d is the bigger number", num1);
    }else if(num2 > num1 && num2 > num3){
        printf("\n %d is the bigger number", num2);
    }else if(num3 > num1 && num3 > num2){
        printf("\n %d is the bigger number", num3);
    }
}
