#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 3

typedef signed long int s32;
s32 * printArray();

s32 i =0;

//try to create main and another function, return an array from another function to the main and print it therir either using static key word before the array array  or save the array at the heap.


s32 main()
{
    printf("please add three numbers to our array :\n ");

    //Return the pointer of the array into this integer
    s32 * arrayPointer = printArray(); //it take element from user and save it at array then return it to the main for print

    //try to print the array using the pointer that recived the array pointer from the printArray() after saving it as static

    for(i=0; i<ARRAYSIZE; i++){

        printf("Element no %d is : %d\n", i+1, *(arrayPointer+i));  // increment pointers either using   *(arrayPointer+i)    or  arrayPointer[i]
    }

    return 0;
}

s32 * printArray(){
    // first try to solve it using static keyword before the initialization of the array to save it and prevent it from being deleted due to new iteration of the function and being deleted from the stack.
        static s32 intArr [ARRAYSIZE] ;
        printf("first no, second no, third no : ");

        for(i=0; i<ARRAYSIZE; i++){

            scanf("%d", &intArr[i]);

        }
        return intArr;


}
