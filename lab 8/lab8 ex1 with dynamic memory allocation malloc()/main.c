#include <stdio.h>
#include <stdlib.h>

typedef signed long int s32;

//functioin prototype.
int* IncrementArray(s32 size);

s32 i = 0;
s32 main()
{
    s32 size = 0;
    printf("Please enter how many numbers you want \n" );
    scanf("%d", &size);

    s32 * ptrfMain = IncrementArray(size);

    for(i=0; i < size; i++){    //loop to scan over the user input and place it to the newely created array at the heap.
        printf("enter input no %d\n", i+1);
        scanf("%d",ptrfMain+i);
    }

    for(i=0; i<size; i++){
        printf("input no %d : %d\n", i+1 ,*(ptrfMain+i));

    }
    return 0;
}


int* IncrementArray(s32 size){

    s32 * ptrf = (s32 *)malloc(size * sizeof(s32));     //create an array inside the heap

    return ptrf;
}
