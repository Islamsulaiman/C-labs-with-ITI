#include <stdio.h>
#include <stdlib.h>

void main()
{
    int number = 0;

    while(1){

    printf("please enter a number : \n");
    scanf("%d",&number);

    if (number % 2 == 0){
        printf("This is even, dont worry\n");
    }else{
        printf("this is odd\n");
    }
    }

}
