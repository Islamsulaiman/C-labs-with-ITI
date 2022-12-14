#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 3

int i =0;
int input = 0;
int main()
{
    int arr[ARRSIZE];

    printf("please input 3 numbers\n");

    for (i=0 ; i<ARRSIZE; i++){
        printf("Please enter input no %d...\n", i+1);
        scanf("%d", &arr[i]);
    }


    printPointer(&arr);


    return 0;
}


void printPointer(int * ptr){
    //int value = *ptr;

    for (i =0; i<ARRSIZE; i++){
        printf("Number %d = %d \n", i+1, ptr[i]);
    }
}








