#include<stdio.h>

#define natural(n)({\
int s=n*(n+1)/2;\
printf("Sum of natural numbers till %d is %d",n,s);\
})

#define fact(n)({\
int i=1,fact=1;\
if(n==0){ printf("Factorial of %d is %d",n,fact);}\
else{\
    while(i<=n){\
        fact*=i;\
        i++;\
    }\
printf("Factorial of %d is %d",n,fact);\
}\
}\
)

