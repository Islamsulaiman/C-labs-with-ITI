#include <stdio.h>
#include <stdlib.h>

#define LENGTH 20

int i = 0;
int main()
{
    char testCase [20] = "islam sulaiman";

    int counter=0;

    for(i=0; i < strlen(testCase); i++){
        if(32 != testCase[i] && '\0' != testCase[i] ){      //to avoid counting whitespace.
            counter++;
        }
    }

    printf("The word is %d letters long", counter);

    return 0;
}
