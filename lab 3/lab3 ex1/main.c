#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total = 0;
    int userInput = 0;

    while(total < 100){
        printf("please enter a number to be added :\n");
        scanf("%d", &userInput);
        total += userInput;
        printf("the current number is %d \n", total);
    }
    printf ("we exedded the max ,and the current total is : %d \n", total);


    return 0;
}
