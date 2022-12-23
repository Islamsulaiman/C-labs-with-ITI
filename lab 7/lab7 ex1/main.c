#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 3

typedef signed long int s32;

s32 i = 0;
s32 input = 0;

s32 main()
{
    s32 *ptr = (int *)malloc(ARRSIZE * sizeof(s32));

    //    int arr[ARRSIZE];

    printf("please input 3 numbers\n");

    takeInput(ptr);

    printPointer(ptr);

    return 0;
}

void printPointer(s32 *ptr)
{
    // int value = *ptr;

    for (i = 0; i < ARRSIZE; i++)
    {
        printf("Number %d = %d \n", i + 1, *(ptr + i));
    }
}

void takeInput(s32 *ptr)
{

    for (i = 0; i < ARRSIZE; i++)
    {
        printf("Please enter input no %d...\n", i + 1);
        scanf("%d", ptr + i);
    }
}
