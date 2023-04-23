#include <stdio.h>

#define FIBONACCI(n) do {\
                        int a = 0, b = 1, c, i;\
                        printf("Fibonacci series: ");\
                        for(i = 0; i < n; i++) {\
                            printf("%d ", a);\
                            c = a + b;\
                            a = b;\
                            b = c;\
                        }\
                        printf("\n");\
                    } while(0)

#define PRIME(n) do {\
                    int i, j, isPrime;\
                    printf("Prime numbers up to %d: ", n);\
                    for(i = 2; i <= n; i++) {\
                        isPrime = 1;\
                        for(j = 2; j < i; j++) {\
                            if(i % j == 0) {\
                                isPrime = 0;\
                                break;\
                            }\
                        }\
                        if(isPrime) printf("%d ", i);\
                    }\
                    printf("\n");\
                } while(0)

#define LEAP_YEAR(year) do {\
                            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))\
                                printf("%d is a leap year.\n", year);\
                            else\
                                printf("%d is not a leap year.\n", year);\
                        } while(0)

int main() {
    int n, year;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    FIBONACCI(n);
    printf("Enter the value of n to generate prime numbers up to n: ");
    scanf("%d", &n);
    PRIME(n);
    printf("Enter a year to check if it's a leap year: ");
    scanf("%d", &year);
    LEAP_YEAR(year);
    return 0;
}
