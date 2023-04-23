%{
#include<stdio.h>
void yyerror();
int yylex();
int flag=0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E{
printf("\nResult=%d\n",$$);
return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
| NUMBER {$$=$1;}
;
%%
void main()
{
printf("\nEnter any arithmetic expression which can have operations: \nAddition, \nSubtraction,\nMultiplication, \nDivison\n");
yyparse();
}
void yyerror()
{
printf("\nEntered arithmetic expression is Invalid\n\n");
flag=1;
}