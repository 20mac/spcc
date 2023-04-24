#include<stdio.h>
#include"natural_fact.h"

void main(){

int n,choice;
printf("1.Natural\n2.Factorial");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
    case 1:printf("Enter value of n:");
            scanf("%d",&n);
            natural(n);
            break;
    case 2:printf("Enter value of n:");
           scanf("%d",&n);
           fact(n);
           break;
}
}
