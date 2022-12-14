#include <stdio.h>
#include <stdlib.h>
#define CUSTOMERS 3

typedef struct customer{
    char name[20];
    int accountNo;
    int balamce;
}customer;

customer arrCustomer[CUSTOMERS];


int i = 0;
int main()

{
    takeCustomers();

    printf("customers less than 200$ \n");
    printf("**************************\n");
    lessThan200();

    printf("**************************\n");

    printf("After adding 100 dollar to every customer with more than 1000 $\n");
    moreThan1000();


    return 0;
}




void takeCustomers(){

    for (i=0; i<CUSTOMERS; i++){
        printf("please enter customer no %d\n", i+1);

        printf("Name : \n");
        scanf("%s",arrCustomer[i].name);

        printf("Account : \n");
        scanf("%d",&arrCustomer[i].accountNo);

        printf("balance : \n");
        scanf("%d",&arrCustomer[i].balamce);

    }

}

void lessThan200 (){
    for(i=0; i<CUSTOMERS; i++){

        if(arrCustomer[i].balamce < 200){
            printf("Customer %d Name : %s \n", i+1, arrCustomer[i].name);
        }

    }
}

void moreThan1000 (){

    for(i=0; i<CUSTOMERS; i++){

        if(arrCustomer[i].balamce >= 1000){

            arrCustomer[i].balamce = arrCustomer[i].balamce + 100;

            printf("Customer %d Name : %s had before %d then it is now %d\n", i+1, arrCustomer[i].name, arrCustomer[i].balamce - 100, arrCustomer[i].balamce);
        }
    }

}


