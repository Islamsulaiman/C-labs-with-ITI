#include <stdio.h>
#include <stdlib.h>

int main()
{




    printf("Please enter number 1 ,operation (+ - / *) , numner 2\n");

    /* Input two number and operator from user */
    scanf("%f%c %f", &num1, &op, &num2);

    /* Switch the value and perform action based on operator*/
    switch(op)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            printf("wrong operator");
    }

    /* Prints the result */
    printf("%.2f %c %.2f = %.2f", num1, op, num2, result);


}
