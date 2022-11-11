#include <stdio.h>
#include <stdlib.h>

// 1- Write a C program to check whether a given number is positive or negative or zero

void main()
{
    int number = 0;
    printf("please enter a number : \n");

    while (1)
    {
        scanf("%d", &number);

        if (number < 0)
        {
            printf("negative number");
        }
        else if (0 == number)
        {
            printf("this is zero maaaan!!!");
        }
        else
        {
            printf("this is positve number");
        }
    }
}
