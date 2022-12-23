#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define INPUTSIZE 10

typedef signed char  s8;
typedef signed long int s32;


s32 i = 0;  //for looping

s8 output [INPUTSIZE];

//prototypes
void printOutput ();    // func to print the saved output in our main array
void strCat();          // fuc to concat the new added char with the old array
void strCatFinesh();    // func to only edit on text when the buffer is finish and the cursor is not at the end of line because we want be adding additional letter at the end.
void clrscr();          // to clear the terminal in order to print the new array
void gotoxy(int x,int y);   // to control the cursor location.


s8 ch = 0;              // var to save the user char input.
s32 arrowtracker = 0;   // var to track every move the cursor do, by incrementing or decrementing to know at which index the cursor are.


s32 main()
{
    printOutput();

    while(1){   //to keep looping until user close tirminal

        if(strlen(output) <  INPUTSIZE) {   // if theire is space at the buffer for
            ch = getch();   // take input
            if(-32 == ch || 71 == ch || 79 == ch){      //if extended keys (up, down,..) or home or end keys.
                takeInput ();   // func to check for arrwos and to control cursor
            }else {         //if the input is not extended key
                strCat();
                clrscr();
                printOutput();
            }
        }else{      //if the cursor is at the end of line then append letter

            ch = getch();
            if(-32 == ch || 71 == ch || 79 == ch){      //if extended keys (up, down,..) or home or end keys.
                takeInput ();
            }else {         //if the input is not extended key
                strCatFinesh();
                clrscr();
                printOutput();
            }
        }
    }

    return 0;
}




void strCat(){

    if(arrowtracker < strlen(output)){  // if the cursor location in lower than the main array length this mean that we moved the cursur left

        for (i=0; i<=arrowtracker; i++){    //loop until you reach the cursor location
            output[arrowtracker] = ch;      //change the litter at the cursor location only
            arrowtracker++;                 // increment the cursor location by on to move to the next letter
            break;
        }

    }else{
        for(i=0; i<=strlen(output); i++){

            if ('\0' == output[i] ){ // when you reaach the end of the string, to add at the end only

                arrowtracker++;        // to be always in sync with the last letter in the array
                output[i] = ch;
                output[i+1] = '\0';     // add the string terminator at the end after adding one litter
                break;
            }
        }
    }
}


void strCatFinesh(){

    if(arrowtracker < strlen(output)){  // if the cursor location in lower than the main array length this mean that we moved the cursur left

        for (i=0; i<=arrowtracker; i++){
            output[arrowtracker] = ch;
            arrowtracker++;
            break;
        }
    }
}




void printOutput (){

    printf("%s", output);
    gotoxy(arrowtracker,0);

}


 void clrscr()  //clear screen func
{
    system("cls");
}




void takeInput (){

    if(-32 == ch){      //if extended key we should take input again to identify which one.
        ch = getch();
    }

    //decide what to do if up, down, enter or any key to go back
    if(75 == ch){   //we pressed left
        if(arrowtracker > 0){       //only go left when the cursor didnt reach the start of the string
            arrowtracker--;
            gotoxy(arrowtracker ,0);
        }

    }else if(77 == ch){ //we pressed right

        if(arrowtracker < strlen(output)){      //only go right when the cursor didnt reach the end of the string
            arrowtracker++;
            gotoxy(arrowtracker ,0);
        }

    }else if (71 == ch){        // if press home go to the start of the string
        gotoxy(0 ,0);
        arrowtracker = 0;

    }else if (79 == ch){        // if press end go to the end of the string

        gotoxy(strlen(output) ,0);  //change x location to reach the end of string
        arrowtracker = strlen(output);
    }
}


void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

