#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>


void gotoxy(int ,int );
void delay(int);

void main(void){

    int row, col,value = 0;
    int size = 0;

    printf("Kindly print an odd number : ");
    scanf("%d", &size);

    row = 1;
    col = (size+1)/2;
    value = 1;

    do{
        gotoxy(col * 5, row);
        printf("%5d", value);
        delay(1);
        // if value is odd move bottom
        if(value % size== 0){
            row++;
        }// if Value is even move to top left
        else{
            row--;
            col--;
        }
        // if value go out of table move to last of table
        if (row == 0){
            row = size;
        }

        if (col == 0){
            col = size;
        }
        value++;

    }while(value <= (size * size));
        return 0;
}

void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
