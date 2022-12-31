#include <dos.h>
#include <dir.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// hash values:
#define NUMOFEMPLOYEES 10

void SetColor(int ForgC);
void delay(int number_of_seconds);
void clrscr();
void gotoxy(int x, int y);

char ch = -1;        // to store user input.
int lineNumber = -1; // this line to store the user input for the up and down keys

int enter = 0;

// employees struct
typedef struct employee
{
    int id;
    int salary;
    char name[20];
} employee;

int employeesLength = 0; // counter for how many employees did the user input, will be used at the display function.
int stopAdding = 0;      // to finish adding employees. this is the number inputed by the user to either stop adding employees or continue.

// lines protoypes
void firstSCreen();
void lineZero();
void lineOne();
void addEmployee(employee *employees);
void displayEmploiyees(employee *employees);

int i = 0; // for looping

int empsNumber = 1; // the number of employees to create space with, it started with 1 because we need to initialize our malloc with at least one struct.
// int newEmpsNumber = 0;      // new number of employees add by the user every time he needs more emps.

int main()
{
    employee *employees = (employee *)malloc(empsNumber * sizeof(employee));

    while (1)
    {

        if (-1 == lineNumber && -1 == ch)
        {

            firstSCreen(); // to print the first screen only the first time the screen loads or when going back from another menue.
        }

        printf("\n Use up or down or enter to navigate... \n");

        takeInput(); // to take input from user

        if (0 == lineNumber)
        { // user at first line
            clrscr();
            lineZero();

            if (1 == enter)
            {
                enter = 0; // to be used again
                clrscr();

                printf("please enter the number of the needed employees\n");
                scanf("%d", &empsNumber); // this is the needed employees at this time

                employees = (employee *)malloc(empsNumber * sizeof(employee));
                employeesLength = 0; // to override the written data.

                for (i = 0; i <= empsNumber && 1 != stopAdding && employeesLength < empsNumber; i++)
                { // add employees, empsNumber is the number of employees the user need to add.

                    addEmployee(&employees[i]); // adding employees function

                    employeesLength++; // to increment the number of employees for display function.

                    printf("To finish press 1 or 2 to continue ...\n");
                    scanf("%d", &stopAdding);
                }

                if (employeesLength >= empsNumber)
                {
                    clrscr();
                    printf("you added more employees than allowed\n");
                }

                stopAdding = 0; // so i can add employees again, because if it remains 1 it will never access the loop again.
            }
        }
        else if (1 == lineNumber)
        { // user at second line display screen
            clrscr();
            lineOne();

            if (1 == enter)
            {
                enter = 0; // to be used again
                clrscr();

                for (i = 0; i < employeesLength; i++)
                { // strlen(employees)

                    displayEmploiyees(&employees[i]); // to display the prevuoisly entred employees.
                }
                printf("\nFinish ...\n");
                printf("\n Use up or down to navigate back... \n");
            }
        }
    }

    return 0;
}

void takeInput()
{

    ch = getch();
    if (-32 == ch || 13 == ch)
    { // check the first value inside the keyboard buffer if it = -32 because this is the extended key value.

        while (ch != 72 && ch != 80 && ch != 13)
        {           // keep getting input from user until he inputs up or down or enter.
            ch = 0; // to clear our variable for furthur use.

            ch = getch(); // to get the actual key value.
        }
    }

    // decide what to do if up, down, enter or any key to go back
    if (13 == ch)
    { // if the user input enter to access the internal page
        enter = 1;
    }
    else if (80 == ch)
    { // we pressed up
        if (1 == lineNumber)
        {
            lineNumber = 0; // if we at the upper limit, loop back at the start.
        }
        else
        {
            lineNumber++;
        }
    }
    else if (72 == ch)
    { // we pressed down
        if (0 == lineNumber)
        {
            lineNumber = 1; // if we at the lower limit, loop back at the end.
        }
        else
        {
            lineNumber--;
        }
    }
}

void firstSCreen()
{

    printf("Add employee \n"); // change line 1 color
    printf("Display employee \n");
}

void lineZero()
{

    SetColor(2);               // green color
    printf("Add employee \n"); // change line 1 color
    SetColor(7);               // white color

    printf("Display employee \n");
}

void lineOne()
{

    printf("Add employee \n"); // change line 1 color

    SetColor(2); // green color
    printf("Display employee \n");
    SetColor(7); // white color
}

void addEmployee(employee *employees)
{

    //(*employees).id = i+1; //to add id automatically.
    employees->id = i + 1;

    // add employee data.
    printf("name ..\n");
    scanf("%s", employees->name);
    printf("salary ..\n");
    scanf("%d", &employees->salary);
}

void displayEmploiyees(employee *employees)
{
    printf("List of our employees ..\n");

    printf("Employee no %d...\nName : %s\nsalary : %d \n", employees->id, employees->name, employees->salary);
    printf("****************************\n");
}

void SetColor(int ForgC)
{ // function to change color of the line.
    // add the function with the color nummber ranging from 1 to 15 before the line that i want to change its color.
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void clrscr() // clear screen func
{
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*

#include <stdio.h>
#include <stdlib.h>
#define EMPNUM 3

//2. Employee with Dynamic Allocation and Highlight Menu (allow the user to specify the size of array at runtime).




typedef signed long int s32;
typedef signed char s8;

typedef struct employee{
    s32 id;
    s32 salary;
    s8 name[20];
}employee;

//function prototype
void addEmp(employee * ptrf);
void displayEmp(employee * ptrf);



s32 inputCounter = 0;

s32 i = 0;
s32 main()
{
    //create an array of employees struct dynamically using malloc()
    employee * empArray =  (employee *)malloc(EMPNUM * sizeof(employee));   //create an array of struct employees in the heap and return the address of the first element into a pointer.



    while(1){
        printf("Please add employees ...\n");

        for(i = 0; i < EMPNUM; i++){

            addEmp(&empArray[i]);     //to send the pointer that is pointing to array elements and increment it by the i

            inputCounter ++;
        }
        printf("\n\n************************\n");

        for(i=0; i < inputCounter; i++){

            displayEmp(&empArray[i]);

        }

    }

    return 0;
}




void addEmp(employee * ptrf){

    //(*ptrf).id = i+1;

    printf("enter employee name \n");
    scanf("%s", ptrf -> name);

    printf("enter employee salary \n", ptrf -> salary);
    scanf("%s", ptrf -> name);



}

void displayEmp(employee * ptrf){

    printf("List of our employees ......\n");
    printf("Employee no %d \nname : %s \nsalary : %d\n", ptrf -> id, ptrf->name, ptrf->salary);
    printf("****************************\n");

}
*/
