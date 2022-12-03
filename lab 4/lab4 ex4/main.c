#include <stdio.h>
#include <stdlib.h>


int main()
{
    char firstName[20] , secondName[20];

    printf("please enter your first name\n");


    int termenator = 0;
    int i = 0;
    for(i = 0; i < 20 && termenator != 13; i++){   //loop for the firstname.
        firstName[i] = getch();

        if(13 == firstName[i]){ // that means that we pressed enter so close this loop
            termenator = 13;
            firstName[i] = '\0';    //add the string terminator instead of the ascii value of enter.
            i=0;     // to be used in the second loop.
        }
    }

    termenator = 0;  // to be used in the second loop.

    printf("please enter the second name\n");

        for(i = 0; i < 20 && termenator != 13; i++){   //loop for the secondname.
        secondName[i] = getch();

        if(13 == secondName[i]){ // that means that we pressed enter so close this loop
            termenator = 13;
            firstName[i] = '\0';    //add the string terminator instead of the ascii value of enter.
            i=0;     // to be used in the second loop.
        }
    }



    for(int i = 0; i < strlen(firstName); i++){
        printf("%c", firstName[i]);
    }
    printf(" "); // space between names
    for(int i = 0; i < strlen(secondName); i++){
        printf("%c", secondName[i]);
    }


    return 0;
}
