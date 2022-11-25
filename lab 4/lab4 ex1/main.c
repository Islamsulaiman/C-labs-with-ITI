#include <stdio.h>
#include <stdlib.h>

void swap (int* , int* );
int main()
{
    int num1 =0;
    int num2 = 0;

    printf("please enter two numbers \n");
    scanf("%d %d", &num1, &num2);

    printf("before swapping num1 = %d and num2 = %d \n", num1, num2);

    swap(&num1, &num2);

    printf("After swapping Num1 = %d and num2 = %d", num1, num2);
    return 0;
}

void swap (int* ptr1, int* ptr2){

    int temp = 0;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
