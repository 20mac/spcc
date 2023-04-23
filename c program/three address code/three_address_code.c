#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qQuadruple(char** expression, int n) {
    printf("op\ttarget1\ttarget2\tresult\n");
    for (int i = 0; i < n; i++) {
        char* expR = expression[i];
        char op = expR[3];
        char arg1 = expR[2];
        char arg2 = expR[4];
        char result = expR[0];
        printf("%c\t%c\t%c\t%c\n", op, arg1, arg2, result);
    }
}

void tTriples(char** expression, int n) {
    printf("#\top\ttarget1\ttarget2\n");
    int c = 0;
    for (int i = 0; i < n; i++) {
        char* expR = expression[i];
        char op = expR[3];
        char arg1 = expR[2];
        char arg2 = expR[4];
        printf("%d\t%c\t%c\t%c\n", i+c, op, arg1, arg2);
        if (expR[0] != '\0') {
            ++c;
            printf("%d\t%c\t%c\t%d\n", i+c, expR[1], expR[0], i+c-1);
        }
    }
}

int main() {
    char** exp;
    int n;
    char input[100];
    printf("Enter the number of expressions: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character after the integer input
    exp = (char**) malloc(n * sizeof(char*));
    printf("Enter the expressions:\n");
    for (int i = 0; i < n; i++) {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character from input
        exp[i] = (char*) malloc((strlen(input) + 1) * sizeof(char));
        strcpy(exp[i], input);
    }
    printf("Quadruple:\n\n");
    qQuadruple(exp, n);
    printf("\nTriple:\n\n");
    tTriples(exp, n);
    for (int i = 0; i < n; i++) {
        free(exp[i]);
    }
    free(exp);
    return 0;
}
