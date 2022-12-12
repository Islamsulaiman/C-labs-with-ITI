#include <stdio.h>
#include <stdlib.h>

//lab 2 ex 1 i n lab 5 style

void add (char* op, float* num1, float* num2, float* result);
void display (char* op, float* num1, float* num2, float* result);

int main()
{

    char op;
    float num1, num2, result=0.0f;

    printf("Please enter number 1 ,operation (+ - / *) , numner 2\n");

    /* Input two number and operator from user */
    scanf("%f%c %f", &num1, &op, &num2);

    /* Switch the value and perform action based on operator*/

    add(&op, &num1, &num2, &result);

    display(&op, &num1, &num2, &result);

    return 0;
}



void add (char* op, float* num1, float* num2, float* result){
    switch(*op)
    {
        case '+':
            *result = *num1 + *num2;
            break;

        case '-':
            *result = *num1 - *num2;
            break;

        case '*':
            *result = *num1 * *num2;
            break;

        case '/':
            *result = *num1 / *num2;
            break;

        default:
            printf("wrong operator");
    }
}


void display (char* op, float* num1, float* num2, float* result){
    /* Prints the result */
    printf("%.2f %c %.2f = %.2f", *num1, *op, *num2, *result);

}
