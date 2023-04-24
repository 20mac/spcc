#include<stdio.h>

#define prime(n)({\
int flag=0,i=0;\
if(n==0 || n==1){\
    flag =1;\
}else{\
    for(i=0;i<=n/2;i++){\
        if(n%i==0){\
            flag=1;\
            break;\
        }\
    }\
}\
if(flag==1){\
    printf("%d is not prime",n);\
}else{\
    printf("%d is prime",n);\
}\
})

#define fib(n)({\
int a=0,b=1,c,i;\
printf("%d %d ",a,b);\
for(i=2;i<n;i++){\
    c=a+b;\
    printf("%d ",c);\
    a=b;\
    b=c;\
}\
})

#define leap(n)({\
if(n%400==0){\
    printf("%d is Leap year",n);\
}else if(n%100==0){\
    printf("%d is not Leap year",n);\
}else if(n%4==0){\
    printf("%d is Leap year",n);\
}else{\
    printf("%d is not  Leap year",n);\
}})
