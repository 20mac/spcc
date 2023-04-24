#include<stdio.h>
#include "bin_hex_dec.h"
void main(){

int n;
printf("Enter binary number:");
scanf("%d",&n);

int choice;
printf("\n1.Decimal\n2.Hexadecimal");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
    case 1: printf("\nDecimal Equivalent:%d",bin_dec_hex(n));
            break;
    case 2: printf("\nHexadecimal Equivalent:%lX",bin_dec_hex(n));
            break;
    default:printf("\nWrong choice");
            break;
}

}
