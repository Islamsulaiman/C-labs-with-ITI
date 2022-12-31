#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define INPUTSIZE 10


//4. Continue Line Editor and make it with dynamic allocation, Update your single line editor to add "delete" & "backspace", continue on lab7 ex2(line editor).


typedef signed char  s8;
typedef signed long int s32;


s32 i = 0;  //for looping

//prototypes
s32 mystrlen(char *p);      // to count the str length with pointers not strings.
void printOutput (s8 * output);    // func to print the saved output in our main array
void clrscr();          // to clear the terminal in order to print the new array
void strCat(s8 * output);   // fuc to concat the new added char with the old array
void strCatFinesh(s8 * output); // func to only edit on text when the buffer is finish and the cursor is not at the end of line because we want be adding additional letter at the end.
void takeInput (s8 * output);
void gotoxy(int x,int y);   // to control the cursor location.






s8 ch = 0;              // var to save the user char input.
s32 arrowtracker = 0;   // var to track every move the cursor do, by incrementing or decrementing to know at which index the cursor are.


s32 main()
{
    //create array in the heap

    s8 * output = (s8 *)malloc(INPUTSIZE * sizeof(s8));

    //s32 arraySize = mystrlen(output);   //




    while(1){

        if(mystrlen(output) <  INPUTSIZE) {   // if theire is space at the buffer for
            ch = getch();   // take input
            if(-32 == ch || 71 == ch || 79 == ch){      //if extended keys (up, down,..) or home or end keys.
                takeInput (output);   // func to check for arrwos and to control cursor
            }else {         //if the input is not extended key
                strCat(output);
                clrscr();
                printOutput(output);
            }
        }else{      //if the cursor is at the end of line then append letter

            ch = getch();
            if(-32 == ch || 71 == ch || 79 == ch){      //if extended keys (up, down,..) or home or end keys.
                takeInput (output);
            }else {         //if the input is not extended key
                strCatFinesh(output);
                clrscr();
                printOutput(output);
            }
        }
    }




    return 0;
}






void strCat(s8 * output){

    if(arrowtracker < mystrlen(output)){  // if the cursor location in lower than the main array length this mean that we moved the cursur left or we are at the middele of the line

        for (i=0; i<=arrowtracker; i++){    //loop until you reach the cursor location
            output[arrowtracker] = ch;      //change the litter at the cursor location only
            arrowtracker++;                 // increment the cursor location by on to move to the next letter
            break;
        }

    }else{
        for(i=0; i <= mystrlen(output); i++){

            if ('\0' == output[i] ){ // when you reaach the end of the string, to add at the end only

                arrowtracker++;        // to be always in sync with the last letter in the array
                output[i] = ch;
                output[i+1] = '\0';     // add the string terminator at the end after adding one litter
                break;
            }
        }
    }
}


void strCatFinesh(s8 * output){

    if(arrowtracker < mystrlen(output)){  // if the cursor location in lower than the main array length this mean that we moved the cursur left

        for (i=0; i<=arrowtracker; i++){
            output[arrowtracker] = ch;
            arrowtracker++;
            break;
        }
    }
}




void takeInput (s8 * output){

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

        if(arrowtracker < mystrlen(output)){      //only go right when the cursor didnt reach the end of the string
            arrowtracker++;
            gotoxy(arrowtracker ,0);
        }

    }else if (71 == ch){        // if press home go to the start of the string
        gotoxy(0 ,0);
        arrowtracker = 0;

    }else if (79 == ch){        // if press end go to the end of the string

        gotoxy(mystrlen(output) ,0);  //change x location to reach the end of string
        arrowtracker = mystrlen(output);
    }
}






s32 mystrlen(char *p)
{
    s32 c = 0;
    while(*p!='\0')
    {
        c++;
        *p++;
    }
    return(c);
}


void printOutput (s8 * output){

    for(i=0; i<mystrlen(output); i++){
        printf("%c", *(output+i));
    }
    gotoxy(arrowtracker,0);

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



