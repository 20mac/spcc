#include<stdio.h>
#include"prime_fib_leap.h"

void main(){

int n,choice;
printf("1.Prime\n2.Fibonacci\n3.Leap year");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
    case 1:printf("Enter number:");
            scanf("%d",&n);
            prime(n);
            break;
    case 2:printf("Enter range:");
           scanf("%d",&n);
           fib(n);
           break;
    case 3:printf("Enter year:");
            scanf("%d",&n);
            leap(n);
            break;


}
}
