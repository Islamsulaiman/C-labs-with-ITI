#include <stdio.h>
#include <stdlib.h>

int main()
{
    int power, number, result;

    printf("Please enter number ...\n");
    scanf("%d", &number);

    printf("Please enter power ...\n");
    scanf("%d", &power);

    result = powerFunc(number, power);

    printf("the result of %d^%d is %d", number, power, result);


    return 0;
}

int powerFunc(int number, int power){
    if(power != 0){
        return (number * powerFunc(number, power-1));
    }else{
        return 1;
    }
}










