#include <stdio.h>
#include <stdlib.h>

void check(char);
int main()
{
    while(1){
                char userInput ;
    printf("Please enter a charechter : %c", &userInput);
    scanf("%c", &userInput);

    check(userInput);

    }


    return 0;
}

void check(char x) {
        if(isalpha(x) > 0){
        printf("ok");
    }else{
        printf("not alpha ya banee2adam");
    }
}
