#include <stdio.h>
#include <stdlib.h>

void uperLower(char);

void main()
{
    printf("Please enter any letter :\n");
    char ch = 0;

    ch = getch();
    printf("you entered %c \n", ch);
    uperLower(ch);

}



void uperLower(char ch){
    if(ch < 65){
        printf("please enter a valid char \n");
    }else if(ch >= 65 && ch <= 90){ // from upper to lower
        ch += 32;
        printf("the lower case is %c", ch);
    }else if(ch >= 97 && ch <= 122){
        ch -= 32;
        printf("the upper case is %c", ch);
    }
}
