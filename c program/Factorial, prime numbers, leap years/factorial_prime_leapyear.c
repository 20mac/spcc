#include <stdio.h>

// Macro to generate factorial series
#define FACTORIAL(n) ({ \
    int result = 1; \
    for (int i = 1; i <= n; i++) { \
        result *= i; \
    } \
    result; \
})

// Macro to generate prime number series
#define IS_PRIME(n) ({ \
    int prime = 1; \
    for (int i = 2; i <= n/2; i++) { \
        if (n % i == 0) { \
            prime = 0; \
            break; \
        } \
    } \
    prime; \
})
#define PRIME_NUMBERS(n) ({ \
    for (int i = 2; i <= n; i++) { \
        if (IS_PRIME(i)) { \
            printf("%d ", i); \
        } \
    } \
})

// Macro to generate leap year series
#define IS_LEAP_YEAR(n) ({ \
    (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0); \
})
#define LEAP_YEARS(start, end) ({ \
    for (int i = start; i <= end; i++) { \
        if (IS_LEAP_YEAR(i)) { \
            printf("%d ", i); \
        } \
    } \
})

int main() {
    // Generate factorial of 5
    int factorial = FACTORIAL(5);
    printf("Factorial of 5: %d\n", factorial);
    
    // Generate prime numbers up to 20
    printf("Prime numbers up to 20: ");
    PRIME_NUMBERS(20);
    printf("\n");
    
    // Generate leap years between 2000 and 2020
    printf("Leap years between 2000 and 2020: ");
    LEAP_YEARS(2000, 2020);
    printf("\n");
    
    return 0;
}
