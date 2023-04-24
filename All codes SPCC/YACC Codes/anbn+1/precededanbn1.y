%{
#include<stdio.h>
#include<stdlib.h>
%}

%token A B NL

%%
stmt: AB NL {printf("valid string\n"); exit(0);}
     ;

AB: A AB B
 | B
     ;
%%
int yyerror(char *msg)
{ 
    printf("invalid string\n"); 
    exit(0); 
}

int main() {
    printf("Enter the string:\n"); 
    yyparse();
    return 0;
}
