%{
    #include <stdio.h>
    int operand=0;
    int operator=0;
    int brckets=0;
%}

%%
[0-9]+ {operand++;}
[\+\-\*\/\=] {operator++;}
"(" {brckets++;}
")" {brckets--;}
%%

int main(){
    printf("Enter the arithmetic expression: ");
    yylex();
    if (operand==operator+1 && brckets==0){
        printf("\nExpression is valid\n");
    }
    else{
        printf("\nExpression is invalid\n");
    }
    return 0;
}

int yywrap(){
    return 1;
}