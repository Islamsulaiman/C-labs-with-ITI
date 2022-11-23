#include <stdio.h>
#include <stdlib.h>

//Simple Menu with 3 choices.

void clrscr();  // this function is to clear screen
void mainScreen();  // main menue screen

int main(void)
{

    while(1)
    {

        mainScreen();

        int userInput = 0;    //to navigate menues;
        char ch;           //user input to go back

        scanf("%d", &userInput);

        if(userInput == 1 || userInput == 2 || userInput == 3)
        {

            if(1 == userInput)
            {
                clrscr();
                printf("You are in Main dishes window\n to exit press b\n");

                ch = getche();       //use getch() to take char from user instead of scanf() because its best with chars.
                    printf("%c",ch);
                if('b' != ch)
                {
                    printf("Wrong input !!\n");
                    exit(0);

                }
                clrscr();       //to clear screen before go back;
                userInput = 0;

            }
            else if(2 == userInput)
            {
                clrscr();
                printf("You are in Drinks window\n to exit press b\n");

                ch = getch();

                if('b' != ch)
                {
                    printf("Wrong input !!\n");
                    exit(0);

                }
                clrscr();       //to clear screen before go back;
                userInput = 0;

            }else if(3 == userInput)
            {
                clrscr();
                printf("You are in Drinks window\n to exit press b\n");

                ch = getch();

                if('b' != ch)
                {
                    printf("Wrong input !!\n");
                    exit(0);

                }
                clrscr();       //to clear screen before go back;
                userInput = 0;

            }


        }

    }
            return 0;

}




void mainScreen()
{
    printf("welcome to the menue restorant, we only have 3 pages ^_^\n");
    printf("1_Main dishes\n2_Drinks\n3_Salads\n");
    printf("Please choose a number to a specific menue\n");
}

void clrscr()
{
    system("cls");
}


