#include <dos.h>
#include <dir.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void SetColor(int ForgC);
void delay(int number_of_seconds);
void clrscr();
void gotoxy(int x,int y);

//lines prorotypes
void firstSCreen();
void lineZero();
void lineOne();
void lineTwo();



char ch = -1; //to store user input.
int lineNumber = -1;      //this line to store the user input for the up and down keys

int enter = 0;



int main()
{

while(1){

    //    debug printf("ch at the start = %d \n", ch); ******

    if(-1 == lineNumber && -1 == ch){

      firstSCreen();    //to print the first screen only the first time the screen loads or when going back from another menue.
    }


    printf("\n Use up or down or enter to navigate... \n");

    takeInput ();   //to take input from user

    if(0 == lineNumber){    //user at first line
        clrscr();
        lineZero();


        if(1 == enter){
           enter = 0;   //to be used again
           clrscr();
           printf("We are in line number one \n");
        }

    }else if (1 == lineNumber){ //user at second line
        clrscr();
        lineOne();
        if(1 == enter){
           enter = 0;   //to be used again
           clrscr();
           printf("We are in line number Two \n");
        }
    }else if(2 == lineNumber){  //user at third line
        clrscr();
        lineTwo();
        if(1 == enter){
           enter = 0;   //to be used again
           clrscr();
           printf("We are in line number Three \n");
        }
    }


}

    return 0;
}








void takeInput (){

    ch = getch();
    if(-32 == ch || 13 == ch){ // check the first value inside the keyboard buffer if it = -32 because this is the extended key value.

        while(ch != 72 && ch != 80 && ch != 13){   //keep getting input from user until he inputs up or down or enter.
            ch = 0; // to clear our variable for furthur use.

            ch = getch();   //to get the actual key value.
        }
    }


    //decide what to do if up, down, enter or any key to go back
    if(13 == ch){ //if the user input enter to access the internal page
        enter =1;
    }
    else if(80 == ch){   //we pressed up
        if(2 == lineNumber){
            lineNumber = 0;     //if we at the upper limit, loop back at the start.
        }else{
            lineNumber ++;
        }
    }else if(72 == ch){ //we pressed down
        if(0 == lineNumber){
            lineNumber = 2;     //if we at the lower limit, loop back at the end.
        }else{
            lineNumber --;
        }
    }

}

void firstSCreen(){
        printf(" \n");
        printf("Line 1 \n");
        printf("Line 2 \n");
        printf("Line 3 \n");
        printf("\n");
}

void lineZero(){

    SetColor(2);            //green color
    printf("Line 1 \n");    //change line 1 color

    SetColor(7);            // white color
    printf("Line 2 \n");
    printf("Line 3 \n");

}

void lineOne(){



    printf("Line 1 \n");    //change line 1 color
    SetColor(2);            //green color
    printf("Line 2 \n");
    SetColor(7);            // white color

    printf("Line 3 \n");

}

void lineTwo(){

    printf("Line 1 \n");    //change line 1 color
    printf("Line 2 \n");

    SetColor(2);            //green color
    printf("Line 3 \n");
    SetColor(7);            // white color


}


void SetColor(int ForgC){   //function to change color of the line.
    //add the function with the color nummber ranging from 1 to 15 before the line that i want to change its color.
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }


 void clrscr()  //clear screen func
{
    system("cls");
}


void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

