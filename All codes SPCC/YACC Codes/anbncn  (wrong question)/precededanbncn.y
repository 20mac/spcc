%{
#include<stdio.h>
#include<stdlib.h>
%}

%token A B C NL

%%
stmt: ABC NL {printf("valid string\n"); exit(0);}
     ;

ABC: A AB B BC C
AB: A AB B
BC: B BC C
 | 
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
