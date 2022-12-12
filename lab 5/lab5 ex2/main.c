#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name [20];
    int salary;
}Employee;

Employee arrOfEmployees[5];     //initialize struct
int i =0;                       //to be used in looping

int main()
{


    for (i = 0; i <= 5; i++){
        arrOfEmployees[i].id = i+1;
        strcpy(arrOfEmployees[i].name, "islam");
        arrOfEmployees[i].salary = 1000*(i+1);
    }

    for(i=0; i<5; i++){

        printf("Employee %d name = %s and salary is = %d\n", arrOfEmployees[i].id, arrOfEmployees[i].name, arrOfEmployees[i].salary);
    }
    return 0;
}
