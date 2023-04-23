%{
/* Definition section */
#include<stdio.h>
#include<stdlib.h>
int i,k=0;
%}

%token A B NL

/* Rule Section */
%%
stmt: expr NL { if (i==2*k)printf("valid string\n");else printf("invalid string\n");
			exit(0); }
;
expr:s j
s: s A {i++;} |
j: j B {k++}  |
;
%%

int yyerror(char *msg)
{
/* printf("invalid string\n"); */
exit(0);
}

//driver code
main()
{
printf("enter the string\n");
yyparse();
}
