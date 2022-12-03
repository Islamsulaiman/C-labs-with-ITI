#include <stdio.h>
#include <stdlib.h>
//8) C Program to Remove all Characters in a String Except Alphabet

//void newArray(char* oldArray, char* newArray);
// warning why the program worked without the above prototype ??????????
int main()
{
    char sourceArray [20] = "test case 5 h65"; //try to remove 5
    char distArray[20] ;    //this array to copy to;

    /*
    char* sptr = sourceArray;
    char* dptr = distArray;
    */

    printf("The old Sentence is %s \n", sourceArray);

    newArray(sourceArray, distArray);   //we don't add & before arrays because they are already a pointer (address) to itself.

    printf("The new Sentance is %s \n", distArray);

    return 0;
}


void newArray(char* oldArray, char* newArray){
    if (NULL == oldArray){  //if the test case is empty close the program.
        return;
    }
    while(*oldArray){   //loop while the array have chars
        if(*oldArray >= 65 && *oldArray <= 65 || *oldArray >= 97 && *oldArray <= 122 || *oldArray == ' '){      //if the char is an alpha according to ASCII or a whitespace

            * newArray = *oldArray; //copy the char from old to new
            newArray++;             // move the newArray pointer one step to a new space in the empty array
            oldArray++;             // move the oldArray pointer one step
        }else{
            oldArray++;             // move the oldArray pointer one step, and don't move new because we don't want to copy it to the new.
        }
    }

    // after the while is fineshed and the oldArray is fineshed then stop the newArray with '\0'.
    *newArray == '\0';      //to close the newArray.

}
