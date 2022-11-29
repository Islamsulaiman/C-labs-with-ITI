#include <stdio.h>
#include <stdlib.h>

int main()
{
    while(1){  // infinite loop to check multiple keys without rerunning the program.

        printf("Please enter a number to check if extended key\n");
        char firstKeyValue = 0;

        char secondKeyValue = 0;  // this is the real extended key value if there is.

        firstKeyValue = getch();

        if(-32 == firstKeyValue){ // check the first value inside the keyboard buffer if it = -32 because this is the extended key value.
            printf("this is an extended key\n");
            secondKeyValue = getch();
            printf("The real value for the extended key is %d\n", secondKeyValue);
        }else{
            printf("this is not an extended key\n\n");
            printf("the value is %d\n", firstKeyValue);
        }

    }

    return 0;
}
