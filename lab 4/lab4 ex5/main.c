#include <stdio.h>
#include <stdlib.h>

int i = 0;              //will be used in every loop
int termenator = 0;     // will be used in the entring value step.

//function prototypes
//void checkChar(char* testChar, int arraytSize);
void takeName (char* userInput);

int main(){

    char userInput [20], ch;        // save user input here.
    printf("enter string to check :\n");

    takeName(&userInput);    // this will save the entered name to userInput.

    printf("\n please enter a char to check the number of :\n");

    scanf("%c", &ch);        //to take a char for testing


/*
    char testChar = 0;      //the char in test from the entered value.

    char testedChars[20];   //save here the tested chars so I dont searsh for them again;
    */

    int counter = 0;
    //create the loop to go over each char in the array.
    for(i = 0; i<strlen(userInput); i++){
        if (ch == userInput[i]){
            counter++;
        }

        //checkChar(&testChar, strlen(userInput));   // to test how many times the chart is duplicated, takes the letter and the array input.
    }


    if(0 == counter){
        printf("this char is not in our test case !!");
    }else{
        printf("The char %c appeared %d times \n", ch, counter);
    }


    return 0;
}





void takeName (char* userInput){        // this will take and save the entered name to userInput.

    for(i=0; i < 20 && termenator != 13; i++){
        userInput[i] = getch();

        if (13 == userInput[i]){
            termenator = 13;
            userInput[i] = '\0';
        }
    }
    printf("print the name\n");

    for(i=0; i<strlen(userInput); i++){
        printf("%c", userInput[i]);
    }

    termenator = 0; // for furthur usee
    i = 0;
}


/*
void checkChar(char* testChar, int arraytSize){     // to test how many times the chart is duplicated.
    for(i = 0; i < arraytSize; i++){
        printf("\nthis is the pointer inside checkChar %x and this is char %c \n", *testChar, *testChar);

    }
}
*/


















