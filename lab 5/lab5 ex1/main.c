#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    int salary;
    int bouns;
    int deduction;
};

int main()
{
    struct student islam;

    islam.id = 1;
    strcpy(islam.name, "islam");
    islam.salary = 10000;
    islam.bouns = 100;
    islam.deduction = 50;

    int islamNetSalary = islam.salary + islam.bouns + islam.deduction;

    printf("Emp1 \nId = %d \nname = %s \nNet salary = %d \n", islam.id, islam.name, islamNetSalary);

    return 0;
}
