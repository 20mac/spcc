#include <stdio.h>

#define FACTORIAL(n) \
({ \
    int result = 1; \
    for (int i = 1; i <= (n); i++) { \
        result *= i; \
    } \
    result; \
})

#define SUM_OF_NATURAL_NUMBERS(n) \
({ \
    int result = 0; \
    for (int i = 1; i <= (n); i++) { \
        result += i; \
    } \
    result; \
})

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    int factorial = FACTORIAL(n);
    printf("Factorial of %d is %d\n", n, factorial);
    
    int sum = SUM_OF_NATURAL_NUMBERS(n);
    printf("Sum of natural numbers up to %d is %d\n", n, sum);
    
    return 0;
}
