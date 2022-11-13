#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x = 0, y = 0, z = 0;
    while(1){

     printf("please enter three numnbers : \n");
    scanf("%d %d %d", &x, &y, &z);

    if (x > y && x > z){
        printf("x is the biggest\n");

    }else if(y > x && y > z){
        printf("y is the biggest\n");

    }else{
        printf("z is the biggest\n");

    }
    }

}
