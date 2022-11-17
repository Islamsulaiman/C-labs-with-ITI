#include <stdio.h>
#include <stdlib.h>

void main()
{
    int grade = 0;

    while(1){
        printf("please enter your grade : \n");
        scanf("%d", &grade);

    if (grade <= 50){
        printf("fail \n");

    }else if (grade >= 85 && grade <= 100) {

            printf("Excellent \n");

    }else if(grade >= 75 && grade < 85){

        printf("V good \n");

    }else if(grade >= 65 && grade < 75){

        printf("good \n");

    }else if (grade >= 50 && grade < 65){
        printf("pass\n");

        }

        }
    }


