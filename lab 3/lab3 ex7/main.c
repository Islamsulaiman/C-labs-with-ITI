#include <stdio.h>
#include <stdlib.h>

void cube (void);
int main()
{
    printf("please enter a number\n");
    cube();
    return 0;
}

void cube (void){
    int userInput=0;
    scanf("%d", &userInput);
    int cube = userInput *userInput *userInput;
    printf("the cube is %d\n", cube);
}
