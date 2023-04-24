%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
%}
%token num
%left '+' '-'
%left '*' '/'
%%
input:exp {printf("Result: %d\n",$$);exit(0);}
exp:	exp'+'exp {$$=$1+$3;}
		|exp'-'exp {$$=$1-$3;}
		|exp'*'exp {$$=$1*$3;}
|exp'/'exp { if($3==0){printf("Divide by Zero. Invalid expression.\n");exit(0);}
		else $$=$1/$3;}
		|'('exp')'{$$=$2;}
		|num{$$=$1;};
%%
int yyerror()
{
	printf("Error. Invalid Expression.\n");
	exit(1);
	return 1;
}
int main()
{
	printf("Enter an expression:\n");
	yyparse();
	return 0;
}