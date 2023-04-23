#include <stdio.h>
#include <string.h>

// Macro to convert binary to decimal
#define BINARY_TO_DECIMAL(binary) ({ \
    int decimal = 0; \
    int base = 1; \
    int len = strlen(binary); \
    for (int i = len-1; i >= 0; i--) { \
        if (binary[i] == '1') { \
            decimal += base; \
        } \
        base *= 2; \
    } \
    decimal; \
})

// Macro to convert binary to hexadecimal
#define BINARY_TO_HEXADECIMAL(binary) ({ \
    int decimal = BINARY_TO_DECIMAL(binary); \
    char hexadecimal[16]; \
    int i = 0; \
    while (decimal != 0) { \
        int remainder = decimal % 16; \
        if (remainder < 10) { \
            hexadecimal[i] = remainder + '0'; \
        } else { \
            hexadecimal[i] = remainder + 55; \
        } \
        i++; \
        decimal /= 16; \
    } \
    hexadecimal[i] = '\0'; \
    strrev(hexadecimal); \
    hexadecimal; \
})

int main() {
    // Convert binary 1010 to decimal
    int decimal = BINARY_TO_DECIMAL("1010");
    printf("Binary 1010 in decimal: %d\n", decimal);
    
    // Convert binary 1010 to hexadecimal
    char* hexadecimal = BINARY_TO_HEXADECIMAL("1010");
    printf("Binary 1010 in hexadecimal: %s\n", hexadecimal);
    
    return 0;
}
