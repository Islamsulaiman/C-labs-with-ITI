#include <stdio.h>
#include <stdlib.h>

int i = 0;
int main()
{
    char userString [20]= "basha";

    char copy[20];

    printf("the copied word is :");

    for(i = 0; i < strlen(userString); i++){
        copy[i] = userString[i];
        printf("%c", copy[i]);
        }




    return 0;
}
