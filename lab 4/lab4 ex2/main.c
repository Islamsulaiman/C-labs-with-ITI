#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("please enter characters max 10 chars long, then i will add string terminator to it\n");

    char userInput [10];

    int i = 0;
    char ch = 0;

    int terminator = 0; // this line is to terminate the for loop

    for(i = 0; i < 10 && terminator != 13; i++){  // 13 is the ascii for enter
        printf("character %d   ", i+1);
        userInput[i] = getch();
        //scanf("%c", userInput[i]);

        if (13 == userInput[i]){
            userInput[i] = '\0';
            terminator = 13;
        }
    }
    printf("The characters are :\n");

    for(int i=0; i < strlen(userInput); i ++){

        printf("%c", userInput[i]);
    }

    return 0;
}
